//Cracked by Roath
// Based on Jay 10/7/96
// ���͵���ѩɽ����
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
		  ���չ��Ŀ�ɽ��ʦ��ɽͯ�ϣ�ʦ������ң�ɡ���ң�ɵ��书
    �ǵ���һ����һֱ�������������е�һ������������֯�����չ�
	��һ��������书�����������������޲�����������ʹ����֣�ֻ
	����Զ���������չ����������չ������������أ��书��ǿ����ʽ
	�ݶ�������������ȱ�ֶ��ȣ�����зϡ������������˶����չ���
	��ɥ����",
});
int ask_menpai(string* message);

void create()
{
	set_name("���", ({ "lingjiu dizi", "dizi", "phoenia" }));
	set("long", "һ����Ŀ�����Ů�ӣ�ֻ��üĿ��һ��ɱ����\n");
	set("gender", "Ů��");
	set("age", 18);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 140);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("���չ�", 5 , "����");
	set("inquiry", ([
			"���չ�"   :  (: ask_menpai, menpai:),
		]));

	setup();
 	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/city/npc/obj/doupeng")->wear();
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
	        command("wanfu " + me->query("id"));
		command("lovelook");
		command("say ��λ" + RANK_D->query_respect(me) + "����������ɽ���չ�����������Ժ�����ʲô���С�\n"+
	     "����ʲ���������Ҿͺ�����"+HBRED+HIW"(ask dizi about ���չ�) (help lingjiu)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
