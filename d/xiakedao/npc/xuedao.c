//Cracked by Roath
// Based on Jay 10/7/96
// ���͵���Ѫ���ŵ���
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          Ѫ����ͬѩɽ�ɶ��������ڡ�Ѫ������һ��С���ɣ�����
    ����Ѫ�����档Ѫ���ľ��С���Ѫ�񵶡������޴��ȿ��Լ�һ
    ��������ͿѪ����һ�беУ��Ҹ���Խ�ߣ�����Խ��ѩɽ�ɺ�
    Ѫ���ŵ��书�кܶ๲֮ͬ������Ϊ���������������ͬʱѧ
    ϰ�书Ҳ������ġ�",
});
int ask_menpai(string* message);

void create()
{
	set_name("��ɱ", ({ "xuedao dizi", "dizi", "slama" }));
	set("long", "һ����ʮ����ĺ��ӣ���ò���䣬��͸��һ��ɱ����\n");
	set("gender", "����");
	set("age", 28);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 125);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("Ѫ����", 4 , "����");
	set("inquiry", ([
			"Ѫ����"   :  (: ask_menpai, menpai:),
		]));

	setup();
        carry_object("/d/qilian/obj/lamajiasha")->wear();
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
	        command("rob");
		command("say ��λ" + RANK_D->query_respect(me) + "ȱǮ���𣿿�������Ҳû��ô��ˮ���ɴ�����һ��ȥ��Ǯ�ɣ�������Ѫ�����������"+
	     "����ʲ���������Ҿͺ�����"+HBRED+HIW"(ask blue about Ѫ����) (help mizong)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
