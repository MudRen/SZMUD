// Code of ShenZhou

inherit NPC_TRAINEE;

int return_home(object home);
#include "/clone/horse/horse.h"
int condition_check();
void create()
{
	set_name("������", ({ "yili ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 10);
	set("long", "����һƥ�������������������ɳ۳Ұ˰��\n");
	set("msg_fail", "$n����$Nŭ˻һ��������������");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N���߰����������Ե�ʮ�ָ��ˣ�");
        set("attitude", "peaceful");

	set("wildness", 6);
	set("value", 140);
	set("ability", 5);

	set("ridable", 1);
	set("str", 80);
        set("con", 40);
	set("dex", 50);
        set("int", 20);
	set("max_qi", 800);
	set("qi", 800);
	set("max_jingli", 900);
	set("combat_exp", 15000);
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