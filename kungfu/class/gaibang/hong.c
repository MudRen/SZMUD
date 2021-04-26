// Code of ShenZhou
// Modified by xbc; add quests 06/21/97
// Modified by xuy; fixed crashing bugs in quests 08/11/97
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

int auto_perform();
int improve_gbskill(string arg);
string ask_wugou();

void create()
{
        set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
        set("nickname", "��ָ��ؤ");
        set("gender", "����");
        set("age", 75);
        set("long", 
"��һ�ų����������΢�룬���ִ�ţ������·���һ����һ��Ĵ����˲�����
ȴϴ�øɸɾ��������ϸ��Ÿ������Ĵ��«��\n");
        set("attitude", "peaceful");
        
        set("str", 35);
        set("int", 24);
        set("con", 30);
        set("dex", 30);

        set("rank", 10);

        set("chat_chance", 1);
        set("chat_msg", ({
                "���߹����Ŷ�Ƥ̾�����������þ�û�Ե��ض��յ�С���ˡ�����\n",
                "���߹������½���һ�ɣ���ʼ˯������˯���૵����������л����������㣡���㣡��\n",
                "���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",
                "���߹�ҡͷ̾������������С�л���ô���񶼲����ղ��ˣ���\n",
                "���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
//              (: random_move :),
        }));
        set("inquiry", ([
                "������" : "�Ͻл���û�������ô�����£���ȥ������С��ɣ�\n",
                "������" : "����������������\n",
                "ؤ��" : "����������������\n",
                "С��" : "����Ե����ض��յĽл�����ţ�����������������ײˣ���������������\n",
                "�óԵ�" : "����Ե����ض��յĽл�����ţ�����������������ײˣ���������������\n",
                "����" : "����ղˣ���ȥ����������������Щ�óԵ����ɡ�\n",
                "�ղ�" : "����ղˣ���ȥ����������������Щ�óԵ����ɡ�\n",
                "����" : "��С�����յĽл�����ţ�����������������ײˣ���������óԡ�\n",
                "�ض�" : "��С�����յĽл�����ţ�����������������ײˣ���������óԡ�\n",
                "�����޹�" : (: ask_wugou :),
//              "��ʦ" : "�����ȥ�����ŵ��Ұ��ܶ��³�нš�\n",
        ]));

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

//      set("qi", 4000);
        set("max_qi", 4000);
//      set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 300);
        
        set("combat_exp", 3600000);
        set("score", 200000);
        set("death_times",180);

        set_skill("force", 400);             // �����ڹ�
        set_skill("huntian-qigong", 400);    // ��������
        set_skill("strike", 400);            // �����Ʒ�
        set_skill("xianglong-zhang", 400);   // ����ʮ����
        set_skill("hand", 360);              // �����ַ�
        set_skill("shexing-diaoshou", 400);  // ���ε��� 
        set_skill("dodge", 400);             // ��������
        set_skill("xiaoyaoyou", 400);        // ��ң��
        set_skill("parry", 400);             // �����м�
        set_skill("stick", 400);             // ��������
        set_skill("dagou-bang", 400);        // �򹷰���
        set_skill("begging", 200);           // �л�����
        set_skill("checking", 200);          // ����;˵
        set_skill("training", 240);          // Ԧ����
        set_skill("digging", 200);  
        
        map_skill("force", "huntian-qigong");
        map_skill("strike","xianglong-zhang");
        map_skill("hand",  "shexing-diaoshou");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("stick", "dagou-bang");
        
        prepare_skill("strike", "xianglong-zhang");

        create_family("ؤ��", 17, "����");
        setup();
        
        if (clonep()) carry_object("/clone/unique/yuzhu-zhang"); //->wield(); 
        carry_object("/d/gaibang/obj/budai")->set_amount(9);
        carry_object("/d/gaibang/obj/budai")->wear();
        if (clonep()) carry_object("/d/gaibang/obj/dahulu"); 
}

void init(){ set_heart_beat(1);}
void attempt_apprentice(object ob)
{

        if (!ob->query_temp("hong_recr")){
        if ((int)ob->query_str() < 28 && (int)ob->query_con() < 28) {
                command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");
                return;
        }

        if ((string)ob->query("family/family_name") != "ؤ��") {
                command("say ��ʦ������ı��£����ֺα�Ҫ���������书��");
                return;
        }

        if( ob->query("rank") >= 6 ) {
                ob->set_temp("title", ob->query("title"));
                command("say �ã������ڱ����ڷ�������������Թ���Ҿ��������ˣ�"); 
                command("recruit " + ob->query("id"));
                ob->set("title", ob->query_temp("title"));
                ob->delete_temp("title");
        } 
        else    command("say �ҿ����ڱ������ʱ�䲻���������������������������Ұɡ�");
        return;
        }

        ob->set_temp("title", ob->query("title"));
        command("recruit " + ob->query("id"));
        ob->set("title", ob->query_temp("title"));
        ob->delete_temp("title");
        ob->delete_temp("hong_recr");
}

int accept_object(object me, object ob)
{
        string myid = me->query("id");
        string name = ob->query("name");
        object dish = this_object()->query_temp("eatting");

// �鲻��һ�쵽�ڲ�ͣ�سԡ�
        if (this_object()->query("food") >= this_object()->max_food_capacity()){
                command("stuff");
                message_vision("$N������$n��ͷ��˵�������ޣ��Ͻл��ҵĶ����Ѿ��Ե�Բ�Ĺĵ�����\n", this_object(), me);
                return 0;
        }

// ���˳Եģ�ʲô����Ҳ���ա�
        if (ob->query("food_supply") <= 0) {
                say((string)me->query("name") + "�����߹�һ" + (string)ob->query("unit") + (string)ob->query("name") + "��\n");
                message_vision("$N������$n��ͷ��˵�������ޣ��Ͻл��Ҳ�Ҫ��������Լ��û�ȥ�ɡ�\n", this_object(), me);
                return 0;
        }

        if( objectp(dish) ) {
                return notify_fail("���߹�����Ʒ��"+dish->query("name")+"����ò�Ҫ��������\n");
        }

// �����л���������
        if (name == "�л���") 
                message_vision("���߹��е�������������������ԵĽл���ѽ��\n", me);
        else if (name == "ţ����" || name == "������" || name == "���ײ�")
                message_vision("���߹��е����������ⲻ���ض�������" + name + "��\n", me);
//      �����ϳԶ��� 
        else if (name == "������" ) {
                say((string)me->query("name") + "�����߹�һ" + (string)ob->query("unit") + name + "��\n");
                message_vision("���߹�����üͷ˵����ô������������\n", me);
                return 0;
        }
        else {
// ����ʳ���Ҫ��
                say((string)me->query("name") + "�����߹�һ" + (string)ob->query("unit") + name + "��\n");
                command( "say �ף�" + name + "��������ģ�");
                command("hehehe " + myid);
                command( "say �ţ���" + name + "�����ʰ���" + (string)me->query("name") + "���޻��Լ���С����");
                return 0;
        }

        this_object()->set_temp("eatting", ob);
        call_out("eatting", 1, me);

        return 1;
}

private int eatting(object me) 
{
        int ime;
        string name, myid;
        object ob = this_object()->query_temp("eatting");

        if(!objectp(ob) ) return 0;

        name = ob->query("name");
        myid = me->query("id");
        ime = (int)((me->query("kar")-10)/5);
//   ���ò��ó�
        if( name == "�л���" ) {
                if (ob->query("fake")) {
                        if (ob->query("undercook")) 
                                message_vision( "���߹�������ü��������л�����ζ�����󡭡��ţ���򻹲�����\n", me);
                        else if (ob->query("overcook")) 
                                message_vision( "���߹�������ü��������л�������̫���ˣ��Բ��á�\n", me);
                        else 
                                message_vision( "���߹�������ü��������л�����ζ�����ԡ�\n", me);
                        command( "shake "+ myid);
                        command( "say �����ѵ������ض����⣬û���˻�������");
                        command("drop " + ob->query("id"));
                        if( objectp(ob) ) destruct(ob);
                        return 1;
                }
                        
//   �óԵĽл���. ��ͽ
                command("eat " + ob->query("id"));
                if(objectp(ob)) destruct(ob);
                command("taste");
                command("stuff");
                command("haha " + myid);
                command("look " + myid);
                command("say " + (string)me->query("name") + "���޻��սл�������������\n");
                if( me->query("rank") > 1 &&
                    me->query("family/family_name") != "ؤ��" )
                        return 1;

                message_vision("\n$N��Ҫ��$nΪ���ӡ�\n", this_object(), me);
                tell_object(me, YEL "�����Ը��ݺ��߹�Ϊʦ������ apprenticeָ�\n" NOR);
                me->set_temp("hong_recr", 1);

                return 1;
        }

// �����óԵĶ���...

//   ���Ĳ��óԣ���ԭ�ϣ�
        if (ob->query("fake")) {
                message_vision( "���߹�������ü��������" + name + "��ζ�����ԡ������ض��յ�" + name +"�óԡ�\n", me);
                command( "shake "+ myid);
                command("drop " + ob->query("id"));
                if( objectp(ob) ) destruct(ob);
                return 1;
        }

//   �óԵ�С��. ������Ǳ�ܺ;���
        command("eat " + ob->query("id"));
        if(objectp(ob)) destruct(ob);
        command("taste");
        command("stuff");
        command("look " + myid);
        command("say " + (string)me->query("name") + "�����յ�" + name + "ζ��ʵ�ڲ�����");
        if ( me->query("family/family_name") == "ؤ��" ) {
                me->add("potential", 2+random(5));
//              me->add("combat_exp", 3+random(5));
                if (me->query("potential") > me->query("max_potential"))
                me->set("potential", me->query("max_potential"));
        }

//     ���û�̹�����������������һ���ģ�depends on kar����������һ����ÿ��ֻ��ѧһ��
//      ��ʱ�ĳ���������Ҫ�����ˡ�
        if ( ((int)me->query("hong_taught")) != 1) {
                switch(ime) {
                case 1:
                        if ( name != "������" ) return 1;
                        break;
                case 2:
                        if ( name != "���ײ�" ) return 1;
                        break;
                case 3:
                        if ( name != "������") return 1;
                        break;
                default:
                        if ( name != "ţ����" )  return 1;
                        break;
                }

                command("thumb " + myid);
                remove_call_out( "improve_gbskill" );
                call_out( "improve_gbskill", 2, me );
                me->set("hong_taught", 1);
                return 1;
        }
        command( "hehehe " + myid);
        command( "say С���޻��ղˣ����򵥰�����Ҫ�����ٽ̣��������ϼ��ѡ�");
        return 1;

}

int improve_gbskill(object me)
{
        string *hong_skill = ({
                "dagou-bang", "huntian-qigong",  "shexing-diaoshou", 
                "xianglong-zhang",  "xiaoyaoyou" });
        string my_skill = hong_skill[random(sizeof(hong_skill))];
        string skill_name = to_chinese(my_skill);

        int my_level = me->query_skill(my_skill, 1)+1;
        int points;

        message_vision( "���߹���$N˵����С���ޣ�������ָ���㼸�й���ɡ�\n\n", me);

// ������ѧ��ѧ�ÿ���࣬����ء�ÿ�˴�Լѧ 30k ��
        points = my_level*my_level + (int)me->query_int()*1000;
        if ( my_level < 180 ) {
                message_vision( "���߹�һ�Է��ϣ�����Ծ�𣬴�����裬������Ծ����һ��" + skill_name + "ʹ��������\n", me);
                message_vision( "֮�󣬺��߹���ϸϸΪ$N�㲦" + skill_name + "���ù��ķ���\n", me);
        }

        else {
                command( "ah " + (string)me->query("id"));
                command( "say " + (string)me->query("name") + "���޵�" + skill_name + "�������Ͻл���ûʲô�ý�����ˡ�\n");
                message_vision( "���߹�ϸϸΪ$N�㲦��һ��" + skill_name + "���ù��ķ���\n", me);
        }

        me->set("hong_taught", 1);
        me->save();
        log_file("QUESTS", sprintf("hong taught %s(%s) %s by %d points.\n", 
                  me->query("name"), getuid(me), skill_name, points));

        while ( points > 0 ) {
                me->improve_skill(my_skill, my_level*my_level+1);
                points -= my_level*my_level+1;
                ++my_level;
        }

        me->add("quest_exp", 20);

        return 1;
}
string ask_wugou()
{
       object ob,me=this_player();
       if (me->query("family/master_name")!="���߹�")
         return RANK_D->query_respect(this_player())+"�����ز���ʶ���γ������أ�";
        if (me->query("rank")<9 || !me->query("questwg"))
        return RANK_D->query_respect(this_player())+"��δΪ�Ұ����´󹦣����������������ᴫ��!";
       ob=new("/u/slow/questwg/dgb_book");
       if (present("dgb book",me)) return "�ף��Ҳ��Ǹ�������ô";
        if (!ob) return "�ţ�����㵹��û���⣬ֻ�Ǹձ���ĵ��ӽ����ˣ����һ���������ʰɡ�";
        ob->set("master",me->query("id"));
        ob->move(me);
        message_vision("$n�ݸ�$Nһ���򹷰��ס�\n",me,this_object());
        command ("rumor "+me->query("name")+"Ū���˴򹷰��ס�");
        return "��ס���޶���Ҫ�ÿھ�����Ŵ򹷰���������(lingwu)����";
}
#include "/kungfu/class/gaibang/auto_perform.h"

