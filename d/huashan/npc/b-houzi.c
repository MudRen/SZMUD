// Code of ShenZhou
// ��ɽ�����
// qfy 27/7/96
//modified by xiaojian to prevent from using it to dig gold
inherit NPC;

void create()
{
        set_name("�����", ({"ma hou","hou","monkey"}));
        set("race", "Ұ��");
        set("age", 10);
        set("long", "һֻ˶��������㿴������Ҳ��������š�\n");
        set("attitude", "peaceful");
        set("limbs", ({ "ͷ��", "����",  "ǰ֫", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 2000);
        set_temp("apply/attack", 40);
        set_temp("apply/defense",40);
        set_temp("apply/armor", 30);
        set_temp("apply/damage",80);
        set("chat_chance", 12);
        set("chat_msg", ({
                "������꣬�������£�û��̰�����\n",
                "���ҡҡβ�ͣ����ְ�����\n",
                "��ֻ��ﻥ��׷�����˹��������ܿ��ˡ�\n",
                "��ﱧ����С���ӡ�\n",
                "�������ؽ��š�\n",
                (: random_move :)
        }) );
        setup();
}
private void go_home()
{
        if( !living(this_object()) ) return;
        message_vision("$Nһ��һ�����뿪�ˡ�\n", this_object());
        this_object()->move("/d/huashan/husun");
        message_vision("$N�ı������ı��˹�����\n", this_object());
}

void init()
{
        string file;

        ::init();
		file = base_name(environment());
        if( strsrch(file, "/d/huashan/") != 0 ) {

                remove_call_out("go_home");
                call_out("go_home", 1);
                }
}

int accept_object(object me, object obj)
{
        object obj2,ob;
		ob = this_object();
        if ( obj->query("food_supply") && obj->value() >= 0 ) {
           message_vision("�����$N�����־׸��˵�Ц�š�\n", me);
           say("������̻��ʵس���,�����±��"+(string)obj->query("name")+"�Եøɸɾ�����\n");
           me->add("monkey", 1);

           if( (int)me->query("monkey")==15 || (int)me->query("monkey")==25
           || (int)me->query("monkey")==35 || (int)me->query("monkey")==45 ) {
                message_vision("���������$N���·���ʾ��$N��������\n", me);
                message("vision", me->name() + "���Ŵ����������ɽ������ҹյ�һ���ӱ㿴�����ˡ�\n", environment(me), ({me}));
                message("vision", "��һֻ��������˹�����\n", environment(me),({me}));
                write("�����Ŵ������ɽ�����ţ���ת��ת�ظ������ʧ�˷���\n");
                write("�������ã������������һ��ɽ��ǰ��ָ�Ŷ���Ҫ���ȥ��\n");
                write("�����ţ���������Ұ�������ˡ�\n");
                me->move("/d/huashan/yelin1");
                message("vision",me->name()+"���Ŵ�������˹�����\n", environment(me), ({me}) );
           }

           if ( (int)me->query("monkey") == 50 ) {
                message_vision("���������$N���·���ʾ��$N��������\n", me);
                message("vision", me->name() + "���Ŵ����������ɽ������ҹյ�һ���ӱ㿴�����ˡ�\n", environment(me), ({me}));
                message("vision", "��һֻ��������˹�����\n", environment(me),({me}));
                write("�����Ŵ������ɽ�����ţ���ת��ת�ظ������ʧ�˷���\n");
                write("����Լ������ε�·�ߺ�ǰ�����߹��Ĳ�ͬ���������ã������������\n");
                write("һ��ɽ���\n");
                me->delete("monkey");
                me->move("/d/huashan/shandong3");
                message("vision",me->name()+"���Ŵ�������˹�����\n", environment(me), ({me}) );
           }
           
           remove_call_out("destroy_it");
           call_out("destroy_it", 1, obj);
           return 1;
        }
        else {
           say("��ｫ"+(string)obj->query("name")+"���˹�������Ū�˼��£��ƺ���������ô�ã��㶪���ˡ�\n");
           command("shake");
           if (obj->query("money_id")) {
              obj2 = new(base_name(obj));
              obj2->set_amount((int)obj->query_amount());
              obj2->move(environment(me));
              say("����ﶪ��һЩ"+(string)obj->query("name")+"��\n");
           }
           remove_call_out("drop_it");
           call_out("drop_it", 1, obj);

        }   
        return 1; 
}

void drop_it(object obj)
{
        command("drop all");
}

void destroy_it(object obj)
{
        destruct(obj);
}
        

