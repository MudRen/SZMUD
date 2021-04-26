// Code of ShenZhou
// ��ɽС����
// qfy 27/7/96
//modified by xiaojian to prevent using it to dig gold 09/9/00
inherit NPC;

void create()
{
        set_name("С����", ({"hou zi","hou","monkey"}));
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻ�ɰ���С���ӣ��������������ӿ�����ԶЩ���������\n");
        set("attitude", "peaceful");
        set("limbs", ({ "ͷ��", "����",  "ǰ֫", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 500);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 8);
        set_temp("apply/damage", 4);
        set_temp("apply/armor", 3);
        set("chat_chance", 10);
        set("chat_msg", ({
                "һֻС���Ӻ�Ȼ�ܹ������������˸�Ҿ��\n",
                "С����ҡ��ҡβ�͡�\n",
                "��ֻС���ӱı��������ܹ������ֻ���׷����ȥ��\n",
                "С��������Ľű߰���������������档\n",
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
        object obj2;
                
        if ( obj->query("food_supply") && obj->value() >= 0 ) {
           command("drop"+obj->query("id"));
           message_vision("С���Ӹ��˵�����$N�ı�������\n", me);
           set_leader(me);
           say("С���������±��"+(string)obj->query("name")+"�Եøɸɾ�����\n");
           me->add("monkey", 1);

           if( (int)me->query("monkey")==15 || (int)me->query("monkey")==25 
           || (int)me->query("monkey")==35 || (int)me->query("monkey")==45 ) {
                message_vision("С��������$N���·���ʾ��$N��������\n", me);
                message("vision", me->name() + "����С����������ɽ������ҹյ�һ���ӱ㿴�����ˡ�\n", environment(me), ({me}));
                message("vision", "��һֻС�������˹�����\n", environment(me), ({me}));
                write("������С������ɽ�����ţ���ת��ת�ظ������ʧ�˷���\n");
                write("�������ã�С���Ӱ������һ��ɽ��ǰ��ָ�Ŷ���Ҫ���ȥ��\n");
                write("�����ţ�С���ӱ���Ұ�������ˡ�\n");
                me->move("/d/huashan/yelin1");
                message("vision",me->name()+"����С�������˹�����\n", environment(me), ({me}) );
           }    


           if ( (int)me->query("monkey") == 50 ) {
                message_vision("С��������$N���·���ʾ��$N��������\n", me);
                message("vision", me->name() + "����С����������ɽ������ҹյ�һ���ӱ㿴�����ˡ�\n", environment(me), ({me}));
                message("vision", "��һֻС�������˹�����\n", environment(me), ({me}));
                write("������С������ɽ�����ţ���ת��ת�ظ������ʧ�˷���\n");
                write("����Լ������ε�·�ߺ�ǰ�����߹��Ĳ�ͬ���������ã�С���Ӱ������\n");
                write("һ��ɽ���\n");
                me->delete("monkey");
                me->move("/d/huashan/shandong3");
                message("vision",me->name()+"����С�������˹�����\n", environment(me), ({me}) );
           }

           remove_call_out("destroy_it");
           call_out("destroy_it", 1, obj);              
           return 1;
        }
        else {
           say("С���ӽ�"+(string)obj->query("name")+"���˹�������Ū�˼��£��ƺ���������ô�á�\n");
           command("shake");
           if (obj->query("money_id")) {
              obj2 = new(base_name(obj));
              obj2->set_amount((int)obj->query_amount());
              obj2->move(environment(me));
              say("С���Ӷ���һЩ"+(string)obj->query("name")+"��\n");
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
