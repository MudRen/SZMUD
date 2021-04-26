#include <ansi.h>
       inherit ITEM; 

       void create() 
       { 
               set_name(HIW"留音盒"NOR, ({ "box", "he" }) ); 
               set_weight(10); 
                      set("unit", "个"); 
                      set("long", "一个神秘的留音盒。\n据说是星宿的前辈丁春秋留下的，赶快打开（opem）吧。。。\n"); 
                      set("value", 0); 
                      set("material", "wood"); 
                      set("no_drop", "这样贵重的东西怎么能随便乱丢呢。\n"); 
                      set("no_get", "这样东西不能离开那儿。\n"); 
                      set("no_give", 1); 

              setup(); 
      } 

      void init() 
             {add_action("do_open", "open");       }

      int do_open(string arg) 
      { 
             object me = this_player(); 
object obj;
int i;

             if (me->query("family/family_name")!= "星宿派")
{write(HIG"你打开留音盒，里面传出一阵丁老怪的讥讥声，十分难听。\n你受不了这种破罗嗓子的刺激，连忙扔了这个盒子。\n"NOR); 
destruct(this_object()); 
return 1;
}


if (me->query_skill("pixie-jian",1)>200)
{
for (i=0;i<20;i++) {obj = new("/d/changbai/obj/yinyang-cao.c");obj->move(me);}
write(HIG"你打开留音盒，里面传出一阵秘语，你根据它的指引寻找一堆稀世的草药。\n你仔细一看，正是你练剑需要的药引子，不禁喜出望外。\n"NOR);  
destruct(this_object());
return 1;
}

write(HIM"你打开留音盒，里面传来了熟悉的声音，原来是掌门人传授基本毒技部分修习秘诀的记录。\n你赶紧用心听，用心记，完后仔细体会了一番，发现对自己毒技的修行大有裨益。\n"NOR);
write(HIM"你放了几遍后，全部记牢了，就把盒子扔往一边了。\n"NOR);
me->improve_skill("poison",20000);
me->improve_skill("poison",20000);
me->improve_skill("poison",20000);

destruct(this_object());
return 1;
}
