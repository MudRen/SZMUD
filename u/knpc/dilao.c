#include <ansi.h>  
    
 inherit ROOM; 
        
 void create() 

       {  
          set("short",HIB"小黑屋"NOR); 
            
          set("long",HIB@LONG 
穿过拥挤的外厅，来到偏院旁的一丛假山之内，一间黑忽忽的空屋，坚
实密封一无所有，除了打开那道沉重的铁门, 常年一丝光线也投射不进，
屋 脚隐隐传来阵阵腐臭血腥气味让人喘不透气.
嘿嘿...来了就别妄想出去! 
LONG 
NOR); 
           
          set("exits",([ 
       
              "out":"/d/qilian/dilao",]) 
              ); 
       
          set("item_desc", ([ 
                    "out" : HIC"...外面一片漆黑，你心中突然涌现一股不详的预感!"NOR,  
                   ]));  
          set("cost",1); 
       
             setup(); 
      } 
   
