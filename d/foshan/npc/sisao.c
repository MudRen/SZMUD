// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("����ɩ", ({ "zhong sisao", "zhong", "sisao" }) );
        set("gender", "Ů��" );
        set("age", 47);
        set("long", 
	     "��ͷ��ɢ�ң�������Ѫ����һ��Цһ��ԭ���Ǹ����ӡ�\n");
        set("shen_type", 1);

        set("combat_exp", 100);

        set("attitude", "aggressive");
        set("chat_chance", 10);
        set("chat_msg", ({
                "����ɩ˵����������ү���㳤�����꣬����˫ȫ�����������Ӹ����ͷ��������ү���۾������㰡��\n",
		"����ɩͻȻ���ڵأ��ǵǵǵؿ�ͷ��\n",
		"����ɩ���У�������ү�����ս�����ҹ���������󸻴�󣬰���ǧ�ﰡ��\n",
		"����ɩ���ش�ޣ��Ž�������������С�����������������úÿడ������ү���۾������û͵�˼ҵĶ�԰���\n",
                (: random_move :)
        }) );

        setup();
        carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/caidao")->wield();
}
