#include<iostream>
using std::ostream;
using std::cout;
using std::endl;
class Quote {
public:
  Quote() = default; 
  Quote(const std::string &book, double sales_price):
    bookNo(book), price(sales_price) { }
  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const
    { return n * price; }
  virtual ~Quote() = default; // dynamic binding for the destructor
private:
  std::string bookNo; // ISBN number of this item
protected:
  double price = 0.0; // normal, undiscounted price
};

class Bulk_quote : public Quote { // Bulk_quoteinherits from Quote
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string& book, double p,
    std::size_t qty, double disc) :
    Quote(book, p), min_qty(qty), discount(disc) { }
    // as before

  double net_price(std::size_t n) const override{
    float factor = 1;
    cout << "bulk discount applied" << endl;
    if (100>=n>=min_qty) {
      factor = discount;
    } else if (n>100) {
      factor = ((n-100)+100*discount)/n;
    }
    cout << factor << endl;
    return n*price*factor;
  }

private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};

double print_total(ostream & os,Quote const & item, size_t n)
{
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() // calls Quote::isbn
  << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}


int main(int argc, char** argv){
Quote q("a book", 10.99);
Bulk_quote bq("another book", 12.99, 10, 0.95);

print_total(std::cout, q, 10);
print_total(std::cout, bq, 100);
print_total(std::cout, bq, 110);

}
