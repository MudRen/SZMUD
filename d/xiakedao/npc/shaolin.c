//Cracked by Roath


inherit NPC;
string* menpai = ({
	"say 
          �����似������������ʼ����ĩ����ʱ��������ʮ����ɮ
    ��Ӧ����������֮������ɽ�μ�����ƽ�������ս�ۣ�����ƾ��
    ��Ⱥ�ļ��գ������������ֶ�������򣬱ƽ������䡣ʤ������
    �����ͣ������һ���ܷ�󽫾��⣬����ʮ���˲�Ը�ܷ⣬�ع�
    ���֣���������������ģ���������´�������ء�����������
    ����ɮ�����������⡹�ȡ��ٳ衹���Դ������������书������
    ���� ",
});
int ask_menpai(string* message);

void create()
{
	set_name("�ɺ�", ({
		"xiao heshang",
		"seng",
		"shuzhia",
	}));
	set("long",
		"����ֻ�Ǹ�ʮ�����С���У��������������ƺ��е����ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 125);
	set("score", 1000);


	create_family("������", 37, "����");
	set("inquiry", ([
			"����"   :  (: ask_menpai, menpai:),
		]));

	setup();

      carry_object("/d/shaolin/obj/qing-cloth")->wear();
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
	{	command("buddhi " + me->query("id"));
		command("say ��λ" + RANK_D->query_respect(me) + 
            "��һ����ȥ���Ǻͷ���Ե֮�ˣ����Ұɡ���\n" + 
	    "��ʲ���������Ҿͺ�����(ask seng about ����)��(help shaolin)��");
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
