//by remove 16/09/2001
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("《三字经》", ({"sanzi jing", "jing" ,"book"}));
        set_weight(200);
        if (clonep())
            set_default_object(__FILE__);
        else
        {
            set("unit", "本");
            set("long", 
                   "这是中国古代学童的启蒙读物。\n"
                   "第一页写着：人之初，性本善，性相近，习相远。......\n");
            set("material", "paper");
            set("value", 200);
      }
}
void init()
{
          add_action("do_study", "study");
          add_action("do_study", "du");
}int do_study(string arg)
{
          object me = this_player();
          object ob = this_object();
          int xx = 30 - me->query("int");
          if (xx < 5 )xx =5;
          if (!id(arg)) return 0;
          if ( me->query_skill("literate", 1) <10)
            {write("你是个文盲，先学点文化(literate)吧。\n");return 1;}
          if ( me->query_skill("literate", 1) >20)            
         {write("你已经无法从《三字经》中学到任何知识了。\n");return 1;}
          else {
        if (!present("sanzi jing", me)) return 0;
         
           if ( me->query("jing") < 20 )
          {
             write("你现在过于疲倦，无法专心下来研读新知。\n");
             return 1;
            }        if (me->is_busy())
             {
                write("你现在正忙着呢。\n");
                return 1;
              }        if ( me->is_fighting() )
             { 
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
              }
       message("vision", me->name() + "摇头晃脑，口中喃喃有词。\n", environment(me), me);
         me->improve_skill("literate", random(me->query_int()));
         me->add("jing", -xx);
         write("你研读《三字经》，似乎读书写字也提高了。\n");
       return 1;
}                           
}


