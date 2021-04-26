// Code of ShenZhou
int ask_me();

inherit NPC;

void create()
{
	set_name("���к�", ({ "yun zhonghe", "yun", "zhonghe"}));
	set("nickname", "���׼���");
	set("long", 
"������ļ��ߣ�ȴ�ּ��ݣ������Ǹ���ͣ�һ�������ü����׶�\n");
	set("gender", "����");
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
	set("env/wimpy", 40);
	set("combat_exp", 700000);
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
                "���к�����Ʈ�ݣ�����֮��Ѹ���쳣��\n"
        }) );

 set("inquiry", ([
        "����" : (: ask_me :),
        "�����书" : (: ask_me :),
        ]));

	set_temp("apply/armor", 50);

	set_skill("force", 140);
	set_skill("dodge", 180);
	set_skill("ding-dodge", 180);
	set_skill("ding-force", 140);
	set_skill("ding-unarmed", 140);
	set_skill("parry", 140);
	set_skill("unarmed", 140);
	set_skill("san-sword", 150);
	set_skill("pike", 140);

	map_skill("dodge", "ding-dodge");
        map_skill("force", "ding-force");
        map_skill("unarmed", "ding-unarmed");
	map_skill("pike", "san-sword");

	setup();
	carry_object("/d/xixia/obj/gangzhua")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
        ::init();
        add_action("do_accept", "accept");
}


int ask_me()
{
object me=this_player();
if ((int)me->query_temp("marks/����yun")) 
        {
say("���к׿��˿��㣬����һ�ڣ����̵ģ����ط�û��Ư��С�����������(accept
test)�������Ӳ������㣿\n");
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

if (!(int)me->query_temp("marks/����yun"))
 return notify_fail ("��Ϲ��ʲô��\n");

        if( arg== "test" ) {
                say("\n���к׵��˵�ͷ��˵�����ܺã����ǵ�һ��....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("���к�̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
                        return 1;
                }
                say("\n���к�˵�������ǵڶ���....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("���кס��ߡ���һ����˵��������������಻�����ļһ�....\n");
return 1;
                }
                say("\n���к�˵��������������....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("���к�̾����û��Ư��С������Ҿ�������....\n");
                        return 1;
                }

say("\n���к׷��˷�����˵�����������㻹��������....\n");
                this_player()->set_temp("xixia/testpass", 2);
                this_player()->delete_temp("marks/����yun");
                return 1;
        }
        return 0;
}

