//Created by Lisser on k1-08-17
// tester.c ����

inherit NPC;
#include <ansi.h>

string ask_me();
void welcome(object me);

void create()
{
        set_name("���", ({ "yang feng", "yang", "tester" }));
	set("gender", "����");
	set("age", 30);
        set("title",HIY"������ݿ���"NOR);
	set("long", "����һ����ʮ����������ˣ������������ݵ��ӵ��书�����Ƿ���������ȥ����������\n");
	set("combat_exp", 6500);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 30+random(3));
	set_skill("dodge", 30+random(3));
	set_skill("parry", 30+random(3));
	set_skill("force", 30+random(3));
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

        set("inquiry", ([
                "���" : (: ask_me :),
                "exam" : (: ask_me :),
        ]));

	setup();
}

void init()
{
	object me = this_player();

	if ( interactive(me) )
	{
		remove_call_out("welcome");
		call_out("welcome", 1, me);
	}
}

void welcome(object me)
{
	string name = (me->query("colorname"))?(me->query("colorname")):(me->query("name"));

	command("smile " + me->query("id"));
	command("say " + name + CYN"������������йء�"HIC"���"NOR + CYN"("HIC"exam"NOR + CYN")�����¡�"NOR);

	return;
}

string ask_me()
{
	object me = this_player();
	string nick = (me->query("gender")=="����")?"С�ֵ�":"С����";
	string yesno = nick + "�����Կ�ʼ����(��������������룺���á��� ��can��)";
	command("bow " + me->query("id"));

	if ( wizardp(me) )
	{
		command("hmm");
		command("say " + "�����Ѿ��������ˣ���Ϊ�λ�Ҫ��С�Ŀ�������Ц�أ�");
		return "�������������ˣ�����ȥ��ɢ�İɡ�";
	}

	add_action("do_test", "��");
	add_action("do_test", "can");
	return yesno;
}

int do_test(int count)
{
	object me = this_player();
	object ob = this_object();
	string nick = (me->query("gender")=="����")?"С�ֵ�":"С����";
	string letgo = nick + "����ô���ǾͿ�ʼ�ˡ�";
	string time, word;

	if ( count < 8 )
	{
		 switch ( (count) )
		{
			case 0: time = "һ";
				break;
			case 1: time = "��";
				break;
			case 2: time = "��";
				break;
			case 3: time = "��";
				break;
			case 4: time = "��";
				break;
			case 5: time = "��";
				break;
			case 6: time = "��";
				break;
			case 7: time = "��";
				break;
		}

		 switch ( random(7) )
		{
			case 0: word = "ע���ˣ����ǵ�" + time + "�С�";
				break;
			case 1: word = "��" + time + "���ˣ����Ͱ���";
				break;
			case 2: word = "�Ѿ��ǵ�" + time + "���ˣ���й������";
				break;
			case 3: word = "����" + time + "���ˣ�Ŭ����";
				break;
			case 4: word = "�ɹ�������ǰ���Ѿ��ǵ�" + time + "���ˣ�";
				break;
			case 5: word = "��֣���" + time + "���ˡ�";
				break;
			case 6: word = "С�ģ���" + time + "�У�";
				break;
			case 7: word = "��ס���" + time + "�а���";
				break;
		}

		command("say " + word);
	        COMBAT_D->do_attack(ob, this_player(), query_temp("weapon"));
	        if( (int)this_player()->query("qi") < 0 || !present(this_player(), environment(this_object())) )
		{
			me->reincarnate();
			move("/d/wuguan/damen");
			me->move("/d/wuguan/damen");
			command("shake" + me->query("id"));
			command("say " + nick + "���в�������");
			command("sigh2");
			return;
		}else{
		        count = count + 1;
			call_out("do_test", 1+random(1), count);
			}
	}
	else
	{
		command("congra " + me->query("id"));
		command("say " + nick + "���˷���ȥ�����ҿ��¾����Ѽ����ˣ������ն�ҪС�İ���");
		me->move("/d/wuguan/cheku");
		return;
	}

}