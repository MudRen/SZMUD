#include <ansi.h>
// 苏梦馨(Athena)
// NPC：/u/athena/npc/meir.c

inherit NPC;
int give_hama();
int give_kiss();
int give_qi();
int give_baohe();
void create()
{
        set_name(HIW"玫儿"NOR,({"mei er","meir"}));
        set("gender","女性");
        set("age",18);
        set("per",33);
        set("str",28);
        set("dex",22);
        set("con",30);
        set("int",23);
        set("attitude","friendly");
        set("long","她两颊生辉，神采飞扬，端然是沉鱼落雁之貌、倾城倾国之姿。\n");
         set("inquiry", (["hama":(: give_hama :), 
                      "qi":(:give_qi:),
                      "kiss":(:give_kiss:),
                      "baohe":(:give_baohe:),
                     "name" : "我就是枚儿，请多多关照！",
                    "where" : "这里就是苏梦馨工作的地方。" ,
                     "athena" : "苏梦馨？她不是在工作吗？好象很用功哦！希望你们能够多多支持她！。" ,
]));
        setup();


        set("chat_chance", 2);
        set("chat_msg", ({
 "枚儿掩着嘴，轻轻咳嗽了两声。。\n",
 "枚儿眼往富贵竹发起呆来。\n",
 "枚儿深情道：江湖是一首诗，一首凄婉哀艳的诗。\n",
 "枚儿叹声道：江湖是一首歌，从平静到高潮然后再归于平静。\n",
 "枚儿重声道：江湖是一股气，一股侠气、一股豪气，如火山爆发般绵绵不断。\n",
       }) );

        carry_object("/clone/special/qilin")->wear();
        carry_object("/d/city/obj/flower_shoe")->wear();
        carry_object("/d/city/obj/necklace-diamond")->wear();
       carry_object("/clone/special/yufenguan")->wear();
        carry_object("d/city/obj/pink_cloth")->wear();
        carry_object("/d/city/obj/ring-jade")->wear();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
}
}
int give_hama()
{
       object ob;
       object me=this_player();
       if (me->query("id")=="athena")
{
      ob=new("/u/athena/obj/hama.c");
        message_vision("枚儿给$N一个" + HIC + ob->query("name") + NOR +"。\n", this_player());
      command("ok " + me->query("id"));
       ob->move(me);
      return 1;
}
              command("hmm2 " + me->query("id"));
      return 1;
}

      int give_qi() 
      { 
             object ob; 
             object me=this_player(); 
       if (me->query("id")=="athena")
      { 
            ob=new("/clone/wiz/mihun.c"); 
       message_vision("枚儿给$N一个" + NOR + ob->query("name") + NOR +"。\n", this_player());
            command("addoil " + me->query("id")); 
             ob->move(me); 
            return 1; 
      } 
                    command("sorry " + me->query("id")); 
                    command("say 这是巫师专用物品,不能够给你！"); 
            return 1; 
      } 

int give_baohe()
{
       object ob;
       object me=this_player();
       if (me->query("id")=="athena")
{
            ob=new("/u/athena/obj/baohe.c"); 
      ob=new("/u/athena/obj/baohe.c");
        message_vision("枚儿给$N一个" + HIG + ob->query("name") + NOR +"。\n", this_player());
      command("congra " + me->query("id"));
       ob->move(me);
      return 1;
}
              command("kick5 " + me->query("id"));
      return 1;
}
int give_kiss()
{
       object ob;
       object me=this_player();
       if (me->query("id")=="athena")
       {
             say(name()+WHT"“咣当……”，倒下了，头上好多金色的小鸟“唧唧喳喳”的飞来飞去。 \n"NOR);
             command("shrug");
return 1;
            }
        command("slap " + me->query("id"));
        command("angry " + me->query("id"));
return 1;
}

void greeting(object ob)
{
        if (this_player()->query("id")=="athena")
{
       if( !ob || !visible(ob) || environment(ob) != environment() ) return;
           say(name()+"说道：“苏夢馨，你回来啦！”  \n"NOR);
                 command("massage athena");
                     }
else
{
        if( !ob || !visible(ob) || environment(ob) != environment() )
          return;
               say(name()+HIG"说道：“你好，欢迎光临!”  \n"NOR);
}
}
