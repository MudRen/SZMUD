//Cracked by Roath
// xingxiu.c ���޵���
// Ssy

#include <ansi.h>
inherit NPC;
string* menpai = ({
	"say 
          �����ɵĿ�ɽ��ʦ�����ʦ������ң�ɡ���ң�ɵ��书
�ǵ���һ�������Ƕ�����һ������������Ѳ�ͬ춵��ҵ�����������
�ɵĹ���������Ƕ�������ʦ���Դ�����Ҫ�ڶ������µĹ�������
�����������ϴ����������������������������������޲�̸��ɫ
�䡣",
});
int ask_menpai(string* message);

void create()
{
        set_name("���޺�", ({ "xingxiu dizi", "dizi", "jwh"}));
        set("long", 
                "���������ɸ��֣�����ȥ���������Ҫ��û�а��տɱ�������\n"
                "����������һ��ͭ�࣬һ����һ�߳���ɤ�ӳ�Щ����Ļ���\n");
        set("gender", "����");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);

        set("combat_exp", 250);


        create_family("������", 2, "����");
	set("inquiry", ([
			"����"   :  (: ask_menpai, menpai:),
		]));

        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
"���޺�����ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ�������御����\n",
"���޺�����ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ��¡��䡫�졫�ء���\n",
"���޺�����ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ��š����ޡ��ȡ���\n",
        }) );

        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
        carry_object("/d/xingxiu/obj/tongbo")->wield();
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
	{	
	        command("hehe " + me->query("id"));
		command("say " + RANK_D->query_respect(me) + 
			"���������书���µ�һ��ֻҪ����ƨ���ߣ�\n"+
			"���ܳ���Ͷ�ء�����ʲ���������Ҿͺ�����\n"+
			HBRED+HIW"(ask jwh about ����)"NOR + " �� "+HBRED+HIW"(help xingxiu)"NOR +"��");
		me->set_temp(this_object()->query("id"), 1);
	}
	
}

#include "/d/xiakedao/npc/xkdnpc.h"
