//Cracked by Roath
// Based on Jay 10/7/96
// ���͵���ѩɽ����
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          ��Ĺ����ʦ�ֳ�Ӣ��������ȫ�����ʦ������Я�ֹ��߽�
	�����������з���֮�飬ȴ�޷���֮Ե���ֳ�Ӣ�ĸ�����������
	����֮�ˣ�����֮�꣬���ڹ�Ĺ���ľ�һ������˴�����Ĺһ�ɡ�
	�ֳ�Ӣ����С��Ů����Ī����֦��һ��һа��",
});
int ask_menpai(string* message);

void create()
{
	set_name("�±���", ({ "xueshan dizi", "dizi", "jyxuanb" }));
	set("long", "��Ĺ��Ů���ӡ�\n");
	set("gender", "Ů��");
	set("age", 18);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 140);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("��Ĺ��", 5 , "����");
	set("inquiry", ([
			"��Ĺ��"   :  (: ask_menpai, menpai:),
		]));

	setup();
        carry_object("/d/xueshan/obj/lamajiasha")->wear();
	carry_object("/d/qilian/obj/faling")->wield();
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

void greeting(object me)
{	
        if (me->query_temp(this_object()->query("id")) == 0 )
	{	
	        command("flirt " + me->query("id"));
		command("idle2");
		command("say ��λ" + RANK_D->query_respect(me) + "�������ǹ�Ĺ������������Ȼ�Ƚϼ�į������Ҳ�ܺ��档\n"+
	     "����ʲ���������Ҿͺ�����"+HBRED+HIW"(ask dizi about ��Ĺ) (help gumu)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
