//Cracked by Roath
// Based on Jay 10/7/96
// ���͵�����ü����
// Ssy

inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          �����ɵĴ�����ʦ�ǹ���Ů������Ů��������ʮ�����꣬
    ��Ȼ�󳹴��򣬳���Ϊ�ᣬ���������˶���һ�ɡ������ɰ�����
    ��ã������������Ů�����ʦ̫�����ε��������š�
          ���ҵ��ӳ��Ŵ�˷�̣��������˶ɼ�����ͨ��Ȱ��ս��
    �е���һ�ΣУðն�����ʵ����������Ϊ����ȡ��ʵս���顣
    �����ɲ�ϲ�����������������˳���������������������Ǳ�ܡ�
    �������ڹ��ټ�ʮ��ׯ����������������������˳���ǣ����֮
    �ġ����׷��ơ���С��ڤ�����ܹ�ͨ��ڤ��ׯ����������������
    ����������ʿ����������������ᡢˮ��ȼõľ��硢����ͨ��
    ���鵤֮������⻹�ɰ�������ѧϰ�����׹�צ��",
});

int ask_menpai(string* message);

void create()
{
	set_name("�����", ({ "emei dizi", "dizi", "bwxy" }));
//	set("long", "һλʮ���������Ů�ᣬ����������ף��������������˿������������֮�⡣\n");
	set("long", "������������ף��������������˿������������֮�⡣\n");

	set("gender", "Ů��");
	set("age", 18);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 140);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("��ü��", 5, "����");
	set("inquiry", ([
			"��ü"   :  (: ask_menpai, menpai:),
		]));

	set("chat_chance", 6);
        set("chat_msg", ({
	             "�������: ���Ҭ������С�װ���򿪰ɡ�\n",
                     "�������: ���Ҭ�������Ҹ�ʯ��������һ�����ɡ�\n",
                     "�������: ��ʵ��ˮ�Ⱦ����ˣ�Ҭ�ӵ��ô������ء�������\n",
                     "�������: ��˵��λҽ�����Ҭ�ӣ������Ǹ���Ҭ�ӣ������԰������ˡ�\n",
	}) );
	
	setup();
        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

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
	        command("hi " + me->query("id"));
		command("say ��λ" + RANK_D->query_respect(me) + "������������üɽһ�Σ����ǻ�ӭ֮����\n"+
	     "����ʲ���������Ҿͺ�����"+HBRED+HIW"(ask bwxy about ��ü) (help emei)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
