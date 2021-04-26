//by remove 16/09/2001
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("《千字文》", ({"qianzi wen", "shu", "book"}));
        set_weight(200);
        if (clonep())
            set_default_object(__FILE__);
        else
        {
            set("unit", "本");
            set("long", 
                 "《千字文》\n"                 "［梁］敕员外散骑侍郎　周兴嗣　撰\n");
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
          if (xx < 10)xx = 10;
          
          if (!id(arg)) return 0;
           if ( me->query_skill("literate", 1) <25)
                  {write("你的知识不够读不懂，多学点文化(literate)吧。\n");return 1;}
           if (me->query_skill("literate", 1) >40)            
          { write("你已经无法从《千字文》中学到任何知识了。\n");return 1;}
          else {
        if (!present("qianzi wen", me)) return 0;
         
           if ( me->query("jing") < 30 )
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
       message("vision", me->name() + "口中念到：天地玄黄，宇宙洪荒，日月盈昃，辰宿列张。\n", environment(me), me);
         me->improve_skill("literate", random(me->query_int()));
         me->add("jing", -xx);
         write("你口中诵念《千字文》，似乎读书写字也提高了。\n");
       return 1;
}                           
}





