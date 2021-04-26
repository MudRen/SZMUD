// Code of ShenZhou
#include <ansi.h>

int ask_dahui();
int ask_join();
int ask_weapon();
int ask_sangtu();

inherit NPC;

void create()
{
        set_name("���ϴ�", ({ "wu laoda", "wu", "laoda"}));
        set("long", 
"������ĸߴ󣬳��۳��ȣ���ֻ���ȴ���ַ����������ԣ�һ�����԰׵�����\n����̫��Ѩ�߸߹����ƺ��书��ǿ��\n");
        set("gender", "����");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", 0);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2000);
        set("max_jing",2000);
        set("eff_jing",300);
        set("eff_qi",200);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 150);
        set("env/wimpy", 40);
        set("combat_exp", 800000);
        set("chat_chance_combat", 15);
        
        set("inquiry", ([
        "���ɴ��" : (: ask_dahui :),
        "����" : (: ask_join :),
        "����" : (: ask_weapon :),
        "ɣ����": (: ask_sangtu :),
        ]));

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("ding-dodge", 200);
        set_skill("ding-force", 200);
        set_skill("ding-unarmed", 200);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("san-sword", 200);
        set_skill("pike", 200);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "ding-force");
        map_skill("unarmed", "ding-unarmed");
        map_skill("pike", "san-sword");

        setup();
        if( clonep() )
        {
                carry_object("/d/city/obj/cloth")->wear();
        }
	call_out( "dest", 300 );

 
}

void init()
{
        ::init();
        add_action("do_accept", "accept");
}

int ask_dahui(){
        object me=this_player();
        if (me->query_temp("wulaoda")!=1){
                say("���ϴ����������ģ���������ɣ�����������İ��㣬���������ˣ����ȥɱ��ɽͯ�ѣ���\n���ϴ������˵����������һֻ��ľ�ϡ�\n");
        } else {
say("���ϴ��������л����������������û���ˣ���Ϊ��Ҫ�����ɴ���أ���\n");
                me->set_temp("joinable",1);
                me->delete_temp("wulaoda");
        }
        return 1;
}

int ask_join(){
        object me=this_player();
        if (me->query_temp("joinable")!=1){
                command("? "+me->query("id"));
        } else {
                say("���ϴ��������Ҳ������ɱͯ�����ҿ����书���񡭡���\n");
                say("���ϴ�������ðɣ�������ܽ��������У��Ҿ�������룡��\n");
                say("(������������ϴ���������accept test)\n");
                me->delete_temp("joinable");
                me->set_temp("testable",1);
        }
        return 1;
}


int do_accept(string arg)
{
        object me=this_player();
        mapping guild;

        if (!(int)me->query_temp("testable") && me->query("id")!="wsky")
                return notify_fail ("��Ϲ��ʲô��\n");

        set("combat_exp", me->query("combat_exp"));
        set("jiali", me->query("force")*3/2);
        set("neili",me->query("max_neili"));
        set("max_neili",me->query("max_neili"));
        
        if( arg== "test" ) {
                say("\n���ϴ������С���ˣ����ǵ�һ�У���\n\n");
                
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

                say("���ϴ�̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
                        return 1;
                }
                say("\n���ϴ�˵�������ǵڶ���....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

                say("���ϴ󡸺ߡ���һ����˵��������������಻�����ļһ�....\n");
                return 1;
                }
                say("\n���ϴ�˵��������������....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));
                COMBAT_D->do_attack(this_object(), this_player(),
                query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

                say("���ϴ�̾������....\n");
                return 1;
                }

                say("\n���ϴ�������ã������������ʮ������������ʮ���������ɣ���\n");
                this_player()->set_temp("wu_test", 1);
                return 1;
        }
        return 0;
}

int ask_weapon(){
        object obj, room;
        object weapon;
        object me=this_player();
        object wu=this_object();
        
        room=load_object("/d/xingxiu/xlroom.c");
        
        
        if(!(int)me->query_temp("wu_test")){
                say ("���ϴ����һ����������������ʲô��������\n");
        } else {
                
                say ("���ϴ�һ���֣�˵���������Ժ򡣡�Ȼ���߽�������һƬ�����\n");
                wu->move(room);
                command("get xianglu dao");
                wu->move(environment(me));
                say("Ƭ�̣����ϴ������˻�����\n");
                
                if (!present("xianglu dao",wu)) {
                        say ("���ϴ�˵�����������Ĳ��ɣ������Ѿ������������ˡ���\n");
                        message_vision("���ϴ���$Nһ��ȭ���ﳤ��ȥ��\n",me);
                        destruct(this_object());
                } else {
                        say ("���ϴ������ɱ�˲���û������ͯ�ѵĹ���������ģ�������̲���¶��������ȥ�ðɣ���\n");
                        command("give blade to "+me->query("id"));
                        me->delete_temp("testable");
                        me->delete_temp("wu_test");  
                        CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ����һ��"+HIG"�̲���¶��"NOR+"��", me->query("name")));                    
                        message_vision("���ϴ���$Nһ��ȭ���ﳤ��ȥ��\n",me);
                        destruct(this_object());
                }
                
        }
        return 1;
}

int accept_object(object me, object obj)
{
        switch ((string)obj->query("name")) {
                case "��ҩ":
                if(obj->query("id")!="jin chuangyao");
                if(query("giveyao")){
                        say("���ϴ�˵������л�����Ѿ�����ҩ�ˡ�\n");
                        return 0;
                }
                message("vision",me->name()+"�����ϴ�һ����ҩ��\n",environment(me),
                ({me}));
                command("thank "+me->query("id"));
                set("giveyao",1);
                command("fu jin");
                if(query("givestone")!=1)
say("���ϴ�˵��������л��λ����������������ɣ����ţë�룬��Ҫ�����ϵĴ�ʯ�ⶾ��\n��˵���������������޺�һ�������������\n");
                        
                else {
                        say("���ϴ��֣����������飬���飬����æ����\n");
                        me->set_temp("wulaoda",1);
                        set("cured",1);
                        set("eff_qi",me->query("max_qi"));
                        set("max_qi",me->query("max_qi"));
                        set("qi",me->query("max_qi"));
                        set("neili",me->query("max_neili")*3/2);
                }                       
                return 1;
                case "��ʯ":
                if(obj->query("id")!="cishi") return 0;
                
                if(obj->is_character() || userp(obj)){
                        command("say �һ�Ū�ң�");
                        command("follow "+me->query("id"));
                        command("kill "+me->query("id"));
                        return 0;
                }
                
                if(query("givestone")) {
                        say("���ϴ�˵������л��һ���ʯ�Ѿ����ˡ�\n");
                        return 0;
                }
                message("vision",me->name()+"�����ϴ�һ���ʯ��\n",environment(me),({me}));
                say("���ϴ�Ѵ�ʯ�����˿��ϴ���ֻ���á�ٿ����һ�������뱻�����������⣡\n");
                set("givestone",1);
                if (query("giveyao")!=1) {
                        say("���ϴ�˵�������ෳ��λ������������һЩ��ҩ����\n");
                } else {
                        say("���ϴ��֣����������飬���飬����æ����\n");
                        me->set_temp("wulaoda",1);
                        set("cured",1);
                        set("eff_qi",me->query("max_qi"));
                        set("max_qi",me->query("max_qi"));
                        set("qi",me->query("max_qi"));
                        set("neili",me->query("max_neili")*3/2);
                }    
                return 1;
        }
}

int ask_sangtu(){
        say("���ϴ�ҧ���гݵ�˵������������ƺ��������޺�һ�������������\n");
        return 1;
}

void unconcious(){
        say("���ϴ�һ��������Ӵ�� ת����ܡ�\nֻ����Ӱһ�������ϴ��Ѿ���ʮ�ɿ��⣬׷��׷�����ˡ�\n\n");
        destruct(this_object());
}

void die(){
        say("���ϴ�һ��������Ӵ�� ת����ܡ�\nֻ����Ӱһ�������ϴ��Ѿ���ʮ�ɿ��⣬׷��׷�����ˡ�\n\n");
        destruct(this_object());
}

void dest(){
        say("���ϴ�Ҵ�ææ���뿪�ˡ�\n");
        destruct(this_object());
}
