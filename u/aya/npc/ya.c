//2002.4 by aya     

#include <ansi.h>   
inherit NPC; 

string ask_aya(); 

void create()  
{
        set_name("����",({"a ya"}));  
        set("title",HIM"�������Ѿ��"NOR);  
        set("nickname", "����");
        set("gender","Ů��");
        set("age",15);
        set("long",  
                 "���������СѾ�ߣ��������䲻�����ϳ��������棬\n"         
                 "Ȼ��һ˫ˮ����Ĵ��۾���ȴ͸¶�����ֽ��\n"       
                 "����ר�ĵ������ӡ�\n"); 
        set("attitude", "friendly");

        set("per",50); 
        set("str",20);
        set("int",20); 
        set("con",20);
        set("dex",20); 

        set("qi",4000);
        set("max_qi",4000);
        set("jingli",3000); 
        set("eff_jingli", 3000);
        set("jing",3000); 
        set("max_jing",3000);
        set("neili",5000);
       set("max_neili",5000);
        set("jiali",50); 

        set("combat_exp",2000000);    
        set("score",77);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({ 
                      (: perform_action, "whip.dian" :) 
            })); 

        set_skill("force",250); 
        set_skill("sword",250);
        set_skill("parry",250); 
        set_skill("dodge",250);
        set_skill("cuff",250);
        set_skill("whip",250);
        set_skill("yunu-xinjing",250);
        set_skill("yunu-jianfa",250); 
        set_skill("feiyan-gong",250); 
        set_skill("meinu-quan",250); 
        set_skill("jueqing-bian",250); 

        map_skill("force","yunu-xinjing");   
        map_skill("sword","yunu-jianfa");
        map_skill("parry","jueqing-bian"); 
        map_skill("dodge","feiyan-gong");
        map_skill("whip","jueqing-bian"); 
        map_skill("cuff","meinu-quan"); 
        prepare_skill("cuff", "meinu-quanfa");  

                create_family("��Ĺ��",5, "����");   
         set("inquiry", ([ 
             "aya" : "�Ҽ�С��Ҫ���д����ˣ���Ҫ��Ҫ��Ϣ��\n",    
               ]) );

         setup(); 
         carry_object("/clone/weapon/heilong-bian")->wield(); 
         carry_object("/clone/armor/cloth")->wear();

}

