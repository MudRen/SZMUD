//Cracked by Roath
// bankhuoji  �ش��û��
// Ssy

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("�ش��û��", ({ "huoji", "keeper" }));
        set("str", 20);
        set("gender", "����");
        set("age", 25);
        set("long", "���Ǹ����͵Ļ�ƣ�������Ҳ��Щīˮ��\n");
        set("combat_exp", 8000);
        set("attitude", "friendly");

        setup();
}
