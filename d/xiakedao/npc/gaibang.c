//Cracked by Roath
// gaibang.c ��ؤ
#include <ansi.h>
inherit NPC;
string* menpai = ({
	"say 
          ؤ�������ֵ�һ��������Ľ���ʮ�����Ը���Ϊ����
    ���������ѧ����ʮ�������нϸߵı�����ؤ��Ĵ򹷹�������
    ��һ����Ҫ��ѧ�򹷹�ֻ�аݺ������ֻ��ؤ���������Ӳ��ܰ�
    ������������ǡ�����ؤ����Ӳ�����Ǯׯ���Ǯ����������� 
    ������(beg)��ؤ����ӿ������˯���������Բ�(check)���˹�
    �����ǳ��ؤ����ܵ���ͨ�˴��ؤ������ж����㡣
    (help beg, help check)", 
});
int ask_menpai(string* message);

void create()
{
	set_name("ǧ���", ({ "begger", "qigai", "whytokay"}));
	set("long", 
		"����ؤ���С��ؤ��\n");
	set("gender", "����");
	set("title", "ؤ��һ������");
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

	set("combat_exp", 100);
	set("score", 1000);

	create_family("ؤ��", 20, "һ������");
	set("inquiry", ([
			"ؤ��"   :  (: ask_menpai, menpai:),
		]));

	setup();
	
        carry_object("/d/gaibang/obj/budai")->wear();
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
{	if (me->query_temp(this_object()->query("id")) == 0 )
	{	command("say ��λ" + RANK_D->query_respect(me) + 
			"������ؤ����ң��������ʲ���������Ҿͺ���\n" +
			"��"+HBRED+HIW"(ask begger about ؤ��)"NOR+" ��" +HBRED+HIW"(help gaibang)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}

 }

#include "/d/xiakedao/npc/xkdnpc.h"

