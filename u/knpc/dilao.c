#include <ansi.h>  
    
 inherit ROOM; 
        
 void create() 

       {  
          set("short",HIB"С����"NOR); 
            
          set("long",HIB@LONG 
����ӵ��������������ƫԺ�Ե�һ�Լ�ɽ֮�ڣ�һ��ں����Ŀ��ݣ���
ʵ�ܷ�һ�����У����˴��ǵ����ص�����, ����һ˿����ҲͶ�䲻����
�� �������������󸯳�Ѫ����ζ���˴���͸��.
�ٺ�...���˾ͱ������ȥ! 
LONG 
NOR); 
           
          set("exits",([ 
       
              "out":"/d/qilian/dilao",]) 
              ); 
       
          set("item_desc", ([ 
                    "out" : HIC"...����һƬ��ڣ�������ͻȻӿ��һ�ɲ����Ԥ��!"NOR,  
                   ]));  
          set("cost",1); 
       
             setup(); 
      } 
   
