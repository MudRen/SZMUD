//Cracked by Roath
// wudang.c ��ͯ
#include <ansi.h>
inherit NPC;
string* menpai = ({
	"say 
          �䵱�����������ֵ�̩ɽ�������䵱�������Դ��ġ�̫����
    ������˸յ����־�ѧ���䵱���򾫼�ֻ��һ�׽�����һ��ȭ����
    ��һ���Ṧ�����䵱���Ӷ��ǵ������˹��辫�޵��¾����Դ˳�
    �����䵱������̫���񹦺͵����ķ��кܸ߾���֮ʱ�����˻����
    �Ծȡ�",
});
int ask_menpai(string* message);

void create()
{
	set_name("��ب", ({ "wudang dizi", "dizi", "ugain" }));
	set("long", 
		"�����䵱ɽ��С�����ӡ�\n");
	set("gender", "����");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 200);
	set("score", 1000);


	create_family("�䵱��", 4, "����");
	set("inquiry", ([
			"�䵱"   :  (: ask_menpai, menpai:),
		]));

	setup();
	
	carry_object("/d/wudang/obj/greyrobe")->wear();
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
	{	command("hi " + me->query("id"));
		command("say ��λ" + RANK_D->query_respect(me) + 
			"����ʲ���������Ҿͺ�����\n" +
		         HBRED+HIW"(ask dizi about �䵱)"NOR +" ������ "+HBRED+HIW"help wudang"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
}

#include "/d/xiakedao/npc/xkdnpc.h"
