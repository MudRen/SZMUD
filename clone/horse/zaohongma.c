// Code of ShenZhou
// zaohong-ma.c �����
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int condition_check();
int return_home(object home);

void create()
{
	set_name("�����", ({ "zaohong ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 8);
	set("long", "����һƥ����ƫС�� �����޳��� ����β�̣� ���ڶ�;��̣�
	 ��;������������� �ǳ������ӽ����֡�\n");
	set("msg_fail", "$n����$Nŭ˻һ��������������");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
        set("attitude", "peaceful");

	set("wildness", 4);
	set("value", 35);
	set("ability", 3);

	set("ridable", 1);
        set("str", 30);
	set("con", 30);
        set("dex", 40);
        set("int", 20);

	set("max_jingli", 550);
	set("combat_exp", 5000);
        set_weight(100000);
	set("chat_chance", 50);
        set("chat_msg", ({
                (: condition_check :),
        }) );

        setup();
}

int return_home(object home)
{
        return 1;
}

