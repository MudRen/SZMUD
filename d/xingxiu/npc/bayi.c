// Code of ShenZhou
// npc: /d/xingxiu/npc/bayi.c
// Jay 3/25/96

inherit NPC;
void create()
{
        set_name("����ү", ({ "hu laoye", "hu", "bayi"}));
	set("title","����");
        set("gender", "����");
        set("age", 55);
	set("long","����ү�Ǳ��ص�һ��������Ϊ�����ʡ�\n");
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 10);
        set("attitude","heroism");
        set("inquiry", ([
           "����" : "�����Ű�����İ취���˺ö���ӣ���ʲôҲû��������������Ҳû�ˡ�",
	   "����" : "��������Ҵ�������ֻ����һ��С�ĸ��ҡ�",	
	   "��" : "��������Ҵ�������ֻ����һ��С�ĸ��ҡ�",
           "������" : "�Ұ����ص��ҵĿ������ˡ�",
        ]) );

        set("combat_exp", 25000);
        set("shen_type", -1);
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
           "����ү�����죺ɳ��һ���ӽ���һ���ӣ�����һ����ɳ��һ���ӡ�\n",
           "����ү������󺰣���վ���ҵ�������ø���Ǯ!\n",
           "����ү̾�˿�������������Ҵ�������ֻ����һ��С�ĸ��ҡ�\n",
        }) );
        carry_object(__DIR__"obj/wcloth")->wear();
}

int accept_object(object who, object ob)
{
        object wage;

        if (who->query_temp("biao/bayi") && ob->name()=="����") {
                who->delete_temp("biao/bayi");
		who->delete_temp("apply/short");
                message_vision( "����ү����$N�������ô��ô�ٲŽ������˵����ÿ��㹤Ǯ���У�\n", who);
                wage = new("/clone/money/silver");
                wage->set_amount(4);
                wage->move(who);
                message_vision("����ү���鲻Ը�ظ�$N����������Ϊ���ڵĳ��͡�\n", who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }

	return 0;
}

void destroy_it(object obj)
{
        destruct(obj);
}
