//Cracked by Roath
// daozhu1.c ���͵�������
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

int ask_leave();

void create()
{
        set_name("������", ({ "long daozhu", "long", "daozhu"}));
        set("long", "����üȫ�ף���ɫ�������红ͯ��\n");
        set("
gender", "����");
        set("age", 70);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 35);
        set("con", 25);
        set("dex", 25);
        set("race", "����");    
        set("max_qi", 2000);
        set("qi", 2000);
        set("max_jing", 2000);
        set("eff_jing", 2000);
        set("jing", 2000);
        set("max_neili", 3000);
        set("eff_neili", 3000);
        set("neili", 3000);
        set("max_jingli", 2000);
        set("eff_jingli", 2000);
        set("jingli", 2000);
        set("combat_exp", 2000000);
        set("score", 100000);

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("cuff", 200);
        set_skill("sword", 200);
        
        set("inquiry", ([
                        "��ԭ"   :      (: ask_leave :),
                        "�뵺"   :      (: ask_leave :),
                ]));
        setup();
}
void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

int greeting(object me)
{       mapping skl;
        int count;
        int flag;
        string *sname;
        skl = me->query_skills();
        sname  = sort_array( keys(skl), (: strcmp :) );

// xbc added pigging experience here:
	/*if ((int)me->query("pig_new/played") >= 30) {
		say("����̧ͷ������һ�ۣ�˵����ȥ��ԭ�������ǺǺǡ���\n");
        	me->set_temp("marks/��", 1);
		return 1;
        }*/
        if ((int)me->query("combat_exp") < 250)
        {       say("����̧ͷ������һ�ۣ�˵����������ǳ��\n");
                return 0;
        }
        if (sizeof(skl) < 5)
        {       say("����̧ͷ������һ�ۣ�˵�������򲻹���\n");
                return 0;
        }
        flag = 0;
        for ( count = 0; count < sizeof(skl); count ++)
        {       if (me->query_skill(sname[count], 1) >= 10)
                {       flag = flag + 1;       }
        }
        if (flag <= 5)
        {       say("����̧ͷ������һ�ۣ�˵�������򲻹���\n");
                return 0;
        }
        say("����̧ͷ������һ�ۣ�΢΢һЦ������ȥ�ɡ�\n");
        me->set_temp("marks/��", 1);
}

int ask_leave()
{       
        say("���������㲻���ǣ�ֻ��������ʯ�ڳ���\n");
        return 1;
}
