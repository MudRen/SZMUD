//Cracked by Roath
// Based on Jay 10/7/96
// ���͵����һ�����
// Ssy

inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          �һ���һ���ˡ���а����ҩʦ��������ҩʦ������������
    ֮�������µ�����֮���ʣ�����ϵ��ˡ���а���źš�����а֮
    ��а����������֮����������һ�����һ��������μ����ġ��һ�
    �书�ж�ָ�����ж������裬�һ����ĵ�ָ��ͨ�����һ��ָ��
    ��ʤ���������һ�����Ϊ�����ȴ�����Ŷݼס���������֮����
    ���ֿ��Ȱ���̫������ׯ½�˷����£�ѧЩ�һ�������������
    ͼ�ϵ��ݻ�ҩʦΪʦ��",
});
int ask_menpai(string* message);

void create()
{
	set_name("�����", ({ "taohua dizi", "dizi", "lok" }));
	set("long", "һλ��ʮ����������ˣ�üĿӢ�������ƺ��е�а����\n");
	set("gender", "Ů��");
	set("age", 28);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 200);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("�һ���", 2 , "����");
	set("inquiry", ([
			"�һ���"   :  (: ask_menpai, menpai:),
		]));

	setup();
        carry_object("/d/xixia/obj/robe")->wear();
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
	        command(" " + me->query("id"));
		command("say �һ������Ӹ�����ѧ��ţ�������������������λ" + RANK_D->query_respect(me) + "\n�������һ���һ������ڣ�\n"+
	     "����ʲ���������Ҿͺ�����"+HBRED+HIW"(ask lok about �һ���) (help taohua)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
