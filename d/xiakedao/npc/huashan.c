//Cracked by Roath
// Based on Jay 10/7/96
// ���͵�����ɽ����
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          ��ɽ��ԭΪ����������������ǿ��һ�ɣ�����ɽ��λǰ
    ������Ͳ��ӷ����ѧ�ļ��ⲻͬ����ɽ�����˾�����Ϊ������
    ���ڡ����ڸ��ּ���������ˮ���ݣ�ͬ�Ųٸ꣡������������
    ����ɽ���ʽ΢����ɽ������ҿɰ�����ȺΪʦ��Ů�����ɰ�
    ������Ϊʦ�����书����һ����ˮƽ����ɰݻ�ɽ�߰�������
    Ϊʦ������Ѱ�ҷ�����ѧϰ�����¾Ž�����������Ϊ����Ψһ
    ��ߡ����¾Ž�����������¾Ž����н����ˣ����ж��ǽ���
    ������֮���ò��أ����������֪��",
});
int ask_menpai(string* message);

void create()
{
	set_name("С��", ({ "huashan dizi", "dizi", "mzm" }));
	set("long", "һλʮ��������꣬˫�����գ�һ�ɼ���֮����\n");
	set("gender", "����");
	set("age", 18);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 120);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("��ɽ", 14 , "����");
	set("inquiry", ([
			"��ɽ"   :  (: ask_menpai, menpai:),
		]));

	setup();
	carry_object("/d/city/obj/cloth")->wear();
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
	        command("poem " + me->query("id"));
		command("say ��λ" + RANK_D->query_respect(me) + "����ȥһ�����������������ǻ�ɽ�ɣ�\n"+
	     "����ʲ���������Ҿͺ�����"+HBRED+HIW"(ask lingxiao about ��ɽ) (help huashan)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
