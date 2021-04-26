// Code of ShenZhou
int ask_me();

inherit NPC;

void create()
{
	set_name("Ҷ����", ({ "ye erniang", "ye", "erniang"}));
	set("nickname", "�޶���");
	set("long", 
"һ������Ů�ӣ�������ɫ���ۣ����������ϸ�������Ѫ�ۡ�\n");
	set("gender", "Ů��");
	set("age", 45);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "Ҷ����ͻȻ����ض���˵�����Ժ��ӣ���ޣ��������衣\n",
                "Ҷ����ͻȻ����������ҡҡҡ��ҡ�������š�������\n"
        }) );

	 set("inquiry", ([
        "����" : (: ask_me :),
        "�����书" : (: ask_me :),
        ]));

	set_temp("apply/armor", 50);
	set_skill("force", 160);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("ding-dodge", 160);
	set_skill("ding-force", 160);
	set_skill("ding-unarmed", 160);
	set_skill("liangyi-dao", 170);
	set_skill("strike", 160);
	set_skill("blade", 170);

	map_skill("dodge", "ding-dodge");
        map_skill("force", "ding-force");
        map_skill("unarmed", "ding-unarmed");
	map_skill("blade", "liangyi-dao");
	map_skill("parry", "liangyi-dao");

	setup();
	carry_object("/d/xixia/obj/liuyedao")->wield();
	carry_object("/d/xixia/obj/robe")->wear();
}
void init()
{
        ::init();
        add_action("do_accept", "accept");
}

int ask_me()
{
	object me=this_player();
if ((int)me->query_temp("marks/����ye")) 
        {
say("Ҷ����Цӯӯ�Ŀ��˿��㣬��ط�û�а��ֺ���,��Ҫ�����Ծ�����(accept
test)�ɣ��������㣬Ϊ��Ŀ����۰���\n");
       return 1;
        }
/* else {

say("�Ϻ�����ŭ�ȵ������������ķ�������������һ��š����Ĳ��ӣ�\n");
        return 1;
        }
*/
}

int do_accept(string arg)
{
	object me=this_player();
        mapping guild;
	if (!(int)me->query_temp("marks/����ye"))
	return notify_fail ("��Ϲ��ʲô��\n");
	
        if( arg== "test" ) {
                say("\Ҷ������˵�ͷ��˵�����ܺã����ǵ�һ��....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

               if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("Ҷ����̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
                        return 1;
                }
                say("\nҶ����˵�������ǵڶ���....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("Ҷ����ߡ���һ����˵��������������಻�����ļһ�....\n");
return 1;
                }
                say("\nҶ����˵��������������....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("Ҷ����̾�����Ժ�����Ϊ����᲻��ɱ�㰡...\n");
                        return 1;
                }

say("\nҶ�������˵�����������������ǳ���Ϣ��...\n");
                this_player()->set_temp("xixia/testpass", 2);
                this_player()->delete_temp("marks/����ye");
                return 1;
        }
        return 0;
}

