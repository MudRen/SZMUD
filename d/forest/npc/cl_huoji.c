// Code of ShenZhou
// /d/forest/npc/cl_huoji.c  ���ְ���
// by aln 2 / 98

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("���ְ���", ({ "huoji", "keeper" }));
        set("str", 20);
        set("gender", "����");
        set("age", 25);
        set("long", "���Ǹ����͵Ļ�ƣ�������Ҳ��Щīˮ��\n");
        set("combat_exp", 2500);
        set("attitude", "friendly");

        setup();
}
