// Code of ShenZhou
inherit NPC;
int auto_perform();
int ask_me();

void create()
{
	set_name("�Ϻ�����", ({ "nanhai eshen", "eshen"}));
	set("nickname", "�����ɷ");
	set("long", 
"���˵�һ���Դ�������Ѱ����һ��������¶����ɭɭ�����ݣ�һ���۾�ȴ����Բ��С��\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing",1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 700000);
	set("env/wimpy", 40);
	set_temp("apply/armor", 70);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
                "�Ϻ�����˵��������ģ��ĸ��Ҳ������ӵĻ��������Ӿ�ס������һ��Ť�������Ĳ��ӡ�\n",
                  "�Ϻ�����ͻȻ��ŭ�����������������϶���������������\n",
		"�Ϻ�����ͻȻС���й�â���䣬�������Ϲ�µµһת���㲻�ɵô��˸���ս��\n", 
        }) );

 set("inquiry", ([
	"����" : (: ask_me :),
	"�����书" : (: ask_me :),
        ]));

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("ding-dodge", 150);
	set_skill("ding-force", 150);
	set_skill("ding-unarmed", 150);
	set_skill("strike", 150);
	set_skill("blade", 150);
	set_skill("canglang-bian", 150);
	set_skill("luan-blade", 150);
	set_skill("whip", 150);

	map_skill("dodge", "ding-dodge");
	map_skill("blade", "luan-blade");
	map_skill("parry", "luan-blade");
        map_skill("force", "ding-force");
	map_skill("whip", "canglang-bian");
        map_skill("unarmed", "ding-unarmed");

	setup();
	switch( random(2) )
        {
                case 0:
                         if (clonep()) carry_object("/clone/unique/eweibian", "/clone/weapon/changbian")->wield();
			 if (clonep()) carry_object("/clone/unique/eyujian", "/clone/weapon/gangdao");
                         break;
                case 1:
                         if (clonep()) carry_object("/clone/unique/eyujian", "/clone/weapon/gangdao")->wield();
			 if (clonep()) carry_object("/clone/unique/eweibian", "/clone/weapon/changbian");
			 break;
        }
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_accept", "accept");
}


int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "blade" )
	command("cut " + target->query("id"));
	return;
	}
}

int ask_me()
{
object me=this_player();
if ((int)me->query_temp("marks/����nan")) 
	{	
say("�Ϻ������Ц��һ����Ҫ�ǲ�������������(accept test)�������Ӳ�š������Ĳ��ӣ�\n");
	return 1;
	}
/* else	{
	say("�Ϻ�����ŭ�ȵ������������ķ�������������һ��š����Ĳ��ӣ�\n");
	return 1;
	}�
*/
}

int do_accept(string arg)
{
        mapping guild;
	object me=this_player();
if (!(int)me->query_temp("marks/����nan")) 
return notify_fail ("��Ϲ��ʲô��\n");
        

        if( arg== "test" ) {
                say("\n�Ϻ�������˵�ͷ��˵�����ܺã����ǵ�һ��....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("�Ϻ�����̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
                        return 1;
                }
                say("\n�Ϻ�����˵�������ǵڶ���....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("�Ϻ����񡸺ߡ���һ����˵��������������಻�����ļһ�....\n");
return 1;
                }
                say("\n�Ϻ�����˵��������������....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
		COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("�Ϻ�����̾������ϧ��ûš���������ӵĲ���....\n");
                        return 1;
                }

say("\n�Ϻ�����������һ˫����˵����������ģ�������\n\n");
                this_player()->set_temp("xixia/testpass", 2);
                this_player()->delete_temp("marks/����nan");
		return 1;
        }
        return 0;
}

