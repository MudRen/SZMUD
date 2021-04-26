#include <ansi.h>
inherit NPC;

int auto_perform();


 void create()
 { 
   set_name(" ���ƹ�",({"zhanggui","boss"}));
   set("long",CYN@LONG
�����������ջ���ƹ������ڴ˴��һ�����ʱʱһ����Ц
�ٺٺ�...ɳ��һ���ӣ�����һ����...
LONG
NOR);
   set("nickname",HIY"Ц�滢"NOR);
   set("gender","����");
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
   create_family("������",2,"����"); 
   set("canuse_sanyin",1); 
   set("title",WHT"��ɽ���ſ�ջ"NOR);
   set("inquiry",([
       "name":"�ٺ٣��Ҿ�����ɽ���ſ�ջ���ƹ�",
       "here":"�˴����㲻���ڿ�ջ�����",
       "�ϰ�":"�ٺ٣�����ջ���ǵ���������ϯ�����Сӥ��Ͷ����������Ҫ�������ڰ���ԤԼû��",
       "zhanggui":"��Ҫ��������ƹ��Ǿ������ޣ�����������ô����ʶ��?",
       "boss":"boss? Ŷ���Ҳ���ֵ䣬Ŷ�������ϰ���",
       "sleep":"�룬������",
       "Сӥ��":"Ŷ������Ԥ��Լ�������û����ȥ��Ժ(FUN)��",
       "knpc":"knpc? ��ô󵨣���ֱί�������ܵ�С�������ˣ��Ͻ�ȥ����k",
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
        command("say �����ٱ���ջ��������������·�� ���Һ��ڸ���K��");
        message_vision("���ƹ����ҵĴ��ֶ�$N����������\n", this_player());

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
