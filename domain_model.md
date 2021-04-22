@startuml
object Player  
object Box  
object AI  
object Bullets  
object Pickups  

Player --> Box : hides in  
Player --> Bullets : shoots  
Player --> Pickups : collects  

Box --> Pickups : contains  

AI --> Bullets : Shoots  

Bullets --> Box : destroys  
Bullets --> Player : damages  
Bullets --> AI : damages  
@enduml

![init_domain_model](https://user-images.githubusercontent.com/58521962/115784572-37c58900-a3b6-11eb-82d4-72d528264817.png)
