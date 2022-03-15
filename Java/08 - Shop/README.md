# Shop

## Task instructions

The task is to operate the store using threads.

Goods delivered to a certain store have their own unique names (`String`). A number of goods is included in the delivery. Goods can be delivered in various numbers of items.

Deliveries (`delivery`) can be made at any time. Customers (`threads`) can also appear at any time and request purchase.

We assume that a customer whose purchase cannot be realized is ready to wait in the store for the next delivery of the goods he wants to purchase.

### Shopping

A customer who comes to the store for a product always gives its name and the number of items. If the goods are known and in sufficient quantity, the customer is served by default. However, if the customer's order cannot be handled, the customer thread is to be blocked until the next delivery of the goods with the same name. It may happen that many customers will be waiting for the same product. The delivery of this item is expected to free their threads.

---

## Providing solution

Please provide the code for a class named `Shop` that implements the `ShopInterface` interface.
