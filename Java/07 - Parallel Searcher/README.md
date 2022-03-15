# Parallel Searcher

## Task instructions

You receive from me an object (`HidingPlaceSupplierSupplier`) from which you need to get objects that deliver caches. You pick up a single one each time an object of type (`HidingPlaceSupplier`) containing a large number of boxes `HidingPlace`. Only some of them contain something (`isPresent`). These must be emptied (`openAndGetValue`). After checking and emptying all lockers, you receive another object with lockers (`HidingPlaceSupplier`)

Caches contain valuable items. Their value must be added up. To obtain another object with caches, you must enter the correct value of items hidden in caches in previous object (note: the first object can be retrieved by specifying the value 0).

### Working conditions

- Use multiple threads to search for caches containing content (`isPresent`)
- Only one locker is allowed to be emptied (`openAndGetValue`) at a time
- You can request a new facility with lockers only after viewing the previous one and after downloading and viewing all its lockers. Of course not
this applies to the collection of the first object with caches.
- Only methods from the `Thread` and `Object` classes may be used for thread management in the program. Using other tools (e.g., Concurrent classes,
Nuclear, Enforcer etc.) is prohibited.
- Getting null instead of the object containing the geocaches ends the search.

## Providing solution

Please provide the code for a class named `ParallelSearcher` that implements the `ParallelSearcherInterface` interface.
