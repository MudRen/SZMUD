//Cracked by Roath
// chi.c ���͵����������ŵ���
inherit NPC;
#include <ansi.h>
string* menpai = ({
	"say 
          ���ǽ�����ͨ������µ�һ�����������������ɡ�����
����ʹ������ͷ�ӣ������书��ǿ���������ƣ��������У���������
��ѧ�����ϵ��ӻ���ѧ���ݾ�"+HBRED+HIW"(trap)"NOR +"����������ɱ���֡�",
});
int ask_menpai(string* message);

void create()
{
	set_name("����Ů����", ({ "chilong dizi","dizi" }) );
	set("gender", "Ů��");
	set("age", 15+random(10));
        set("long",
		"���ǳ����ŵ��ӣ���Ͷ���С���ƺ��������¡�\n");
	set("combat_exp", 100);
        set("shen_type", -1);
        set("attitude", "heroism");

	set("apply/attack",  15);
	set("apply/defense", 15);

	set("jingli",100);

	create_family("������", 4, "����");
	set("inquiry", ([
			"������"   :  (: ask_menpai, menpai:),
		]));

      setup();
	switch( random(3) )
        {
                case 0:
			carry_object("/clone/weapon/gangjian")->wield();
			break;
                case 1:
			carry_object("/clone/weapon/changjian")->wield();
                        break;
                case 2:
			carry_object("/clone/weapon/duanjian")->wield();
                        break;
        }

        carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 20);
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
	{	command("flirt " + me->query("id"));
		command("say ��λ" + RANK_D->query_respect(me) + 
		"�������������ɣ����������������Ů��\n" +
		"����ʲ���������Ҿͺ�����"+HBRED+HIW"(ask dizi about ������)"NOR +"������ \n" +
		HBRED+HIW"(help shenlong)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
