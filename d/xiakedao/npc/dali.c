//Cracked by Roath
#include <ansi.h>

inherit NPC;
string* menpai = ({
	"say 
          �����λ����ԭ���Ϸ������ϡ����������츣���꽨��
������һ���Ǵ�����ҡ�����ԭ��������ԭ�������ң����Ϊ���壬
�Ҵ��书ȴ���������ķϣ����������ڷܡ����ϵ�һ��ָ�����񽣣�
���ǽ����Ϻպ��������书��",
});
int ask_menpai(string* message);

void create()
{
        set_name("����", ({ "dali dizi", "dizi", "siluda" }) );
        set("gender", "����");
        set("age", 30);
        set("long",
"����λ����ɮ�ˣ�����ɮ�£�˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
        set("combat_exp", 200);
        set("shen_type", 1);
        set("attitude", "heroism");

        set("str", 28);
        set("con", 23);
        set("int", 20);
        set("dex", 26);

        set("shen_type", 0);

	set("inquiry", ([
			"����"   :  (: ask_menpai, menpai:),
			
		]));

        setup();

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/dali/obj/ycloth")->wear();
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
	{	command("hi " + me->query("id"));
		command("say " + RANK_D->query_respect(me) + "�����Ǵ����������ɣ������Ƕ�ɽ��ˮ�㡣����ʲ��\n" +
"�������Ҿͺ�����"+HBRED+HIW"(ask oom about ����)"NOR+ "��"+HBRED+HIW"(help dali)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
		
 }

#include "/d/xiakedao/npc/xkdnpc.h"


