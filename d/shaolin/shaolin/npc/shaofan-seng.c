// Code of ShenZhou
// Npc: /d/shaolin/npc/shaofan-seng.c
// Date: YZC 96/01/19
// modified by xiaojian on Aug.20,2000
#include "/d/shaolin/npc/tiaoshui2.h"
inherit NPC;

void reward_dest(object me,object obj);
void destroy_tool(object me,object obj);
void destroy_dest(object me,object obj);
string ask_piao();
string ask_tong();
void create()
{
        set_name("�շ�ɮ", ({
                "shaofan seng",
                "shaofan",
                "seng",
        }));
        set("long",
                "����λ���ֵ�����ɮ�ˣ��������Ϊ�����շ����˵�Ե�ʣ�����˷����İɡ�\n"
        );


        set("gender", "����");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 44);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 400);
        set("max_jing", 200);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 10);
        set("combat_exp", 2000);
        set("score", 100);

        set_skill("force", 12);
        set_skill("dodge", 12);
        set_skill("unarmed", 12);
        set_skill("parry", 12);
      set("inquiry", ([
                "here" : "�����������µĳ�����\n",
                "ˮͰ" : (: ask_tong:),
                "tong": (: ask_tong :),
            "ˮư" : (: ask_piao:),
                "piao": (: ask_piao :),
                  ]) );
        setup();

}

private void go_home()
{

        if( !living(this_object()) ) return;
        message_vision("$N��ɫ���ŵ��뿪�ˡ�\n", this_object());
        this_object()->move("/d/shaolin/chufang");
        message_vision("$N�첽���˹�����\n", this_object());
}
        



void init()
{
     if( environment() != load_object("/d/shaolin/chufang") ) 
                {
                remove_call_out("go_home");
                call_out("go_home", 1);
        }
}