// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("��С��", ({ "zhong xiaoer", "zhong", "xiaoer" }) );
        set("gender", "����" );
        set("age", 13);
        set("long", 
	     "���Ǹ�ʮ������ĺ��ӣ�����˫�㣬�¿��ѱ��񹷵�צ��˺��ϡ�ã����һ·������Ѫ��\n");
        set("shen_type", 1);

        set("combat_exp", 100);

        set("attitude", "friendly");

        setup();
        carry_object("/clone/armor/cloth")->wear();
}
