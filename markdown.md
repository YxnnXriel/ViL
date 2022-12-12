# ViL
## My own programming language written in C
  last project of the year 2022

### ---------------------------------------------------------------------------------------------------------------



# Compatibility / download
- [Windows 64bits](./Vilw.exe )
- [Linux (Ubuntu 22.04, Debian)](./Vil) 
<!-- - [MacOs](nac.exe)  --> 

# Contact / help

> Developer's GitHub -> YxnnXriel  

or  

Contact me by email yannariel13@gmail.com for help, ask questions or contribute to the development of this small project.

# Examples

> les types de variables 
```c
    caractère -> char
    boolean -> bool
    integer -> int
    floatant -> float
    liste - > list
    dictionnaire -> dict
    type complexe -> type

```


> variable declaration
```typescript
    var my_variable1; // variable declaration without assignement
    var my_variable2 = @int(21); // whith typé(declaration with method implement for caste)
    var my_variable3 = 21; // variable declaration with automatic typing
    /*
        Vil is weakly typed
    */
```



> conditions

```js
    var nbr = 18

    if nbr < 18 :{
        println("you are underage ");
    }
    else if nbr == 18:{
        println("you have just entered adulthood ");
    }
    else:{
        println("you are of legal age");
    }
```


> loop
```js
    var mult = 2;
    var i = 0;
    
    while i <= 10:{
        println(mult," x ",i," = ",i*mult);
        i+=1;
    }

    for i = 0; i < 10 ; i+=1:{
        println("ViL prog");
    } 

```

> the lists

```js

    var liste = []; // ... = [1,2,3,4] ou ... = @list(1,2,3,4)

    // [ vide ! ] 
    println(liste);

    liste.append(1,2,3,4,"ViL");
    
    // [ 1 , 2 , 3 , 4 , "ViL" ]
    println(liste);

```

> dictionaries

```js

    var dict_food_price = {
        "chocolat":1,
        "burger":12,
        "homar":34,
    };


    println(
        dict_food_price{1} // I did this for the visual and not to confuse between a list and a dictionary
    );

```

> functions and procedures

```go

    func SayHello():{
        println("Hello, world");
    }

    // lambda function
    lfunc SayHiMom():println("Hi, Mom");

    func GetNumber2():{
        return 1+1;
    }

    // not necessary, I emphasize that this function will be called automatically. if there is more than one hand, all hands will be called!
    func main():{
        SayHello()
        SayHiMom()
        println(GetNumber2());
    }

```

> complex types (like struct in C)

```js

    type Personne:{
        ::Personne(name,subname){
            Nom = name
            Prenom = subname
        }

        var Nom::str
        var Prenom::str


        // This function should take nothing as parameters and should return nothing.
        func __print__():{
            println("Nom : ",Nom," Prenom : ",Prenom);
        }

        func __cmp__():{
            return Nom;
        }

        lfunc sayHello():println("Hello");

    }


    var p1::Personne = new Personne("John","Doe");

    println(p1); // Nom : John Prenom : Doe

```

# Next release and other

    you can contact me if you want to help with this little language. see contact / help section

 the possibility of adding your libraries written in C would be brought in the next updates. 

 an example file will be provided for more details on this language in french.

