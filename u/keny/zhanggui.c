#include <ansi.h>
inherit NPC;

int auto_perform();


 void create()
 { 
   set_name(" 程掌柜",({"zhanggui","boss"}));
   set("long",CYN@LONG
他就是这个客栈的掌柜，历年在此打点一切事物，时时一脸奸笑
嘿嘿嘿...沙子一袋子，金子一屋子...
LONG
NOR);
   set("nickname",HIY"笑面虎"NOR);
   set("gender","男性");
   set("age", 57); 
   set("attitude","heroism"); 
   set("str", 50); 
   set("dex", 40); 
   set("con", 50); 
   set("int", 60); 
   set("shen_type", 0); 

   set_temp("apply/armor", 100);
   set_temp("apply/attack", 100);
   set_temp("apply/dodge", 100);    

   set_skill("strike", 200); 
   set_skill("claw", 200); 
   set_skill("zhaixinggong", 200); 
   set_skill("chousui-zhang", 200); 
   set_skill("sanyin-zhua", 200); 
   set_skill("force", 300); 
   set_skill("dodge", 200); 
   set_skill("parry", 200); 
   set_skill("literate", 500); 
   set_skill("staff",400); 
   set_skill("tianshan-zhang",400); 
   set_skill("throwing",300); 
   set_skill("feixing-shu",300);
   set_skill("poison",800); 
   set_skill("huagong-dafa",400); 

   map_skill("dodge", "zhaixinggong"); 
   map_skill("strike", "chousui-zhang"); 
   map_skill("claw", "sanyin-zhua"); 
   map_skill("force", "huagong-dafa"); 
   map_skill("staff","tianshan-zhang"); 

 prepare_skill("strike", "chousui-zhang");
 prepare_skill("claw", "sanyin-zhua"); 
 
   set("jiali",350); 
   set("jiajing",200);
   set("combat_exp", 2000000); 
   set("max_qi", 5800); 
   set("max_jing", 5200); 
   set("neili", 15000); 
   set("max_neili", 8000); 
   create_family("星宿派",2,"弟子"); 
   set("canuse_sanyin",1); 
   set("title",WHT"天山龙门客栈"NOR);
   set("inquiry",([
       "name":"嘿嘿，我就是天山龙门客栈的掌柜",
       "here":"此处？你不就在客栈里面嘛？",
       "老板":"嘿嘿，这间客栈可是当年星宿首席大弟子小鹰子投资所开，你要问他现在啊？预约没？",
       "zhanggui":"你要问这里的掌柜，那就是我罗，不过，我怎么不认识你?",
       "boss":"boss? 哦，我查查字典，哦，就是老板嘛",
       "sleep":"请，里面走",
       "小鹰子":"哦？你有预先约定吗？如果没有请去后院(FUN)等",
       "knpc":"knpc? 你好大胆，敢直委我们老总的小名，来人，拖进去给我k",
       ]));
       
   
   set("chat_chance_combat", 50);
   set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

 
   setup();
   carry_object("/d/xingxiu/obj/yudi.c");
   carry_object("/d/city/obj/cloth")->wear();

}
void init()
{
        add_action("do_kill", "kill");
}

int do_kill(string arg)
{
        object ob;
        int i;

        if (!arg || arg != "zhanggui") return command("kill ");
        
        if (present("da shou", environment(this_object()))){
        command("say 你想打劫本客栈，当真是自找死路！ 左右何在给我K！");
        message_vision("程掌柜左右的打手对$N发动攻击！\n", this_player());

        for(i=0; i<2; i++) {
                if( objectp( ob = present("da shou " + (i+1), environment(this_object())) ) )
                                 ob->kill_ob(this_player());
                else    this_object()->kill_ob(this_player());
        }
        }

        return command("kill zhanggui");
}

int accept_kill(object me)
{
        kill_ob(me);
        command("blow di");
        command("perform sanyin");
        command("perform yiji");
        return 1;
}
