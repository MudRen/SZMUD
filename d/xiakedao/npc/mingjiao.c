//Cracked by Roath
// Based on Jay 10/7/96
// ���͵���ѩɽ����
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          ѩɽ�������ڵ�һ֧��ѩɽ����������Ҫ����Ħ�Ǻ�
    ���ַ������Ħ��ס���ڴ�ѩɽ�����£�Ϊ��ެ����ʦ�����ַ�
    �������ɹ�����ʦ��ѩɽ�ɵ������ַ�����������⽵������
    ѩɽ�ɾ�ѧ���������ϱ��������˹������ˣ����κη������ߣ�
    ������ǮׯȡǮ���㣬���漫������������ѩɽ����ȥ������
    ������ɡ�",
});
int ask_menpai(string* message);

void create()
{
	set_name("����", ({ "xueshan dizi", "dizi", "lama" }));
	set("long", "һ��ʮ�����С���üĿ��һ��ɱ����\n");
	set("gender", "����");
	set("age", 18);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 140);

	set("attitude", "peaceful");
	set("shen_type", -1);

	create_family("ѩɽ", 13 , "����");
	set("inquiry", ([
			"ѩɽ"   :  (: ask_menpai, menpai:),
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
		command("lama");
		command("say ��λ" + RANK_D->query_respect(me) + "��������ѩɽ����������������Ժ�����ʲô���С�\n"+
	     "����ʲ���������Ҿͺ�����"+HBRED+HIW"(ask lama about ѩɽ) (help mizong)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
