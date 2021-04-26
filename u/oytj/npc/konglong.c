inherit NPC;
#include <ansi.h>

object owner, rider;

mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
        "east":         "��",
        "west":         "��",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "��",
        "down":         "��",
        "out":          "��",
        "enter":        "��",
]);

void create()
{
        set_name(HIM "С����" NOR , ({ "kong long", "long"}) );
    set("race", "����");
    set("age", 130);
        set("long", "�ʺ��ר�����\n");

		set("str", 100);
		set("con", 100);
		set("dex", 100);
		set("int", 10);
		set("qi", 100000);
		set("wildness", 4);
		set("value", 1000);
		set("ability", 400);
		set("max_qi", 100000);
                set("owner","oytj");
		set("combat_exp", 100000);
                set("max_jingli", 100000);

		set_weight(500000);

		setup();
}

void init()
{
        ::init();
        add_action("do_ride", "qilong");
        add_action("do_zoulu", "go");
        add_action("do_paolu", "goto");
        add_action("do_qingren", "qingren");
        add_action("do_xialong", "xialong");
        add_action("do_longeat", "longeat");
}
int do_longeat(string arg)
{
        string target, msg;
        object obj, me;
        me = this_player();
        target = arg;
        obj = find_object(target);
        if (me!=owner) return notify_fail("��û��������ѽ��\n"); 
//      if (!wizardp(me)) return notify_fail(HIM"����"NOR"��������Ļ���\n");
        if (!obj) obj = present(target, me);
        if (!obj) obj = present(target, environment(me));
        if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
        if (!obj) return notify_fail("û���������....��\n");
        if( environment(me)==environment(obj) )
        message_vision(HIM"С����"NOR HIY"һ�ڰ�"NOR MAG +obj->query("name")+ NOR HIY"������ȥ��\n"NOR, me, obj);
        destruct(obj);
        write("�����ˡ�\n");
        return 1;
}
int do_qingren(string arg)
{
        object victim, me = this_player();
        string comm;
                
        if (!arg) return notify_fail("����ô�߱��ҿ���\n");
//              if (!wizardp(me)) return notify_fail(HIM"С����"NOR"�����������\n");
                if (owner!=me) return notify_fail(HIM"С����"NOR"������������\n");
        victim = present(arg, environment(me));
                if (rider) return notify_fail(HIM"С����"NOR"ֻ�ܴ�����ˣ��ٶ����Ͳ������ˡ�\n");
        if (!victim) return notify_fail(HIM"С����"NOR"ת�˼�Ȧ�Ҳ�����������ˡ�\n");
        if (!living(victim)) return notify_fail(HIM"С����"NOR"ת�˼�Ȧ������������˻��ˡ�\n");

        message_vision(YEL "$N������"NOR HIM"С����"NOR YEL"��ͷ��ֻ��"NOR HIM"С����"NOR YEL"�������ڵ��ϣ���$N����$n��ȫ������������ͷ�ϡ�\n"NOR, me, victim);

        rider = victim;
        victim->set_leader(me); 
        victim->set_temp("apply/short", ({MAG+victim->name()+"�������ݵ�����"+me->name()+"����"NOR HIM"С����"NOR MAG"ͷ��"+NOR+"("+victim->query("id")+")"}));
        victim->set_temp("apply/long", ({victim->name()+"�������ݵ�����"+me->name()+"����"HIM"С����"NOR"ͷ��\n"}));

                return 1;
}
int do_zoulu(string arg)
{
                object env, obj, ob, me = this_player();
                string target_dir, dir, dest, victim;
                mapping exit;
                string riderstr;

                env = environment(me);
                if (me!=owner) return notify_fail(HIM"С����"NOR"������������\n");
                if (!arg) return notify_fail(HIM"С����"NOR"��ԭ��ת��һȦ��\n");
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) 
                        return notify_fail(HIM"С����"NOR"ת�˼�Ȧ�Ҳ�������ȥ�ķ���\n");
                dest = exit[arg];
        if( !(obj = find_object(dest)) )
                call_other(dest, "��������");
        if( !(obj = find_object(dest)) )
                return notify_fail("�߲��ˡ�\n");
                if( !undefinedp(default_dirs[arg]) )
                target_dir = default_dirs[arg];
        else
                target_dir = arg;
        message_vision(GRN "$N����"NOR HIM"С����"NOR GRN"��"NOR MAG +target_dir+ NOR GRN"���������˳�ȥ��\n" NOR, me);
        
        riderstr = me->name();
        if (rider) {
                riderstr += "��"+rider->query("name");
        }
        if( me->move(obj) ) {
                        message( "vision", GRN +riderstr+"����"NOR HIM"С����"NOR GRN"���������˹�����\n" NOR, environment(me), ({me}));
                        move(obj);
                        if (rider) {
                                rider->move(obj);
                                }
                        return 1;
                        }

        return 0; 
}

int do_paolu(string arg)
{
        int goto_inventory = 0;
        object obj, victim, me = this_player();
        string msg;
                string riderstr;;

                if (me!=owner) return notify_fail(HIM"С����"NOR"������������\n");

        if( !arg ) return notify_fail(HIM"С����"NOR"��ԭ��ת��һȦ��\n");

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail(HIM"С����"NOR"��ԭ��ת��һȦ��\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return me->move(arg);
                        return notify_fail(HIM"С����"NOR"�Ҳ��������ҵ��ˡ�\n");
                }
        }
                if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail(HIM"С����"NOR"ȥ��������ȥ�ĵط���\n");

        if( !me->query("env/invisibility") ) {
                message_vision(MAG"$N����"NOR HIM"С����"NOR MAG"һ���ӳ��˳�ȥ��\n" NOR, me);
        }

        if( me->move(obj) ) {
                                riderstr = me->name();
                if (rider) {
                                riderstr += "��"+rider->query("name");
                                message( "vision", MAG +riderstr+"����"NOR HIM"С����"NOR MAG"���˽�����\n" NOR, environment(me), ({me}));
                                tell_object(rider,HIM"С����"NOR YEL"ͻȻ�������������ŵĽ�����ס"NOR MAG+owner->query("name")+ NOR YEL"��\n"NOR);
                    move(obj);
                                rider->move(obj);
                }               
                        else
                        message( "vision", MAG +riderstr+"����"NOR HIM"С����"NOR MAG"���˽�����\n" NOR, environment(me), ({me}));
            move(obj);
                }
        return 1;
}

int do_ride(string arg)
{
        object victim, me = this_player();
                
//        if (this_player()->query("id")!="oytj") return notify_fail("��Ҫ���ʲʺ���������\n");
//              if (!wizardp(me)) return notify_fail(HIM"С����"NOR"����������ģ�\n");
                if (me->query("env/invisibility")>0) return notify_fail("�Բ���������"HIM"С����"NOR"�������\n");

        victim = this_object();
                if (owner) return notify_fail("�㻹û�����ء�");
                message_vision(CYN "$N����"NOR HIM"С����"NOR CYN"���˻��֣�ֻ��"NOR HIM"С����"NOR CYN"�������ڵ��ϣ���$N���׵�����������ͷ�ϡ�\n", me);
        owner = me;
                victim->set_leader(me);
                victim->set("env/invisibility",10);
                me->set_temp("apply/short", ({MAG+me->name()+"����"NOR HIM"С����"NOR MAG"��ͷ��"+NOR+"("+me->query("id")+")"}));
                me->set_temp("apply/long", ({me->name()+"�������ݵ�����"NOR HIM"С����"NOR"ͷ��\n"}));
        return 1;
}
int do_xialong(string arg)
{
        object victim, me = this_player();
        
//        if (this_player()->query("id")!="oytj") return notify_fail("��Ҫ���ʲʺ���������\n");
//              if (!wizardp(me)) return notify_fail(HIM"С����"NOR"����������ġ�\n");
                if (!arg) {
                        if (me!=owner)  
                                return notify_fail("��û��������ѽ��\n"); 
                victim = this_object();
                message_vision(HIY "$N����һ���"NOR HIM"С����"NOR HIY"��������������\n"NOR, me);
                owner = 0;
                victim->set_leader(me);
                victim->set("env/invisibility",0);
                me->delete_temp("apply/short");
                me->delete_temp("apply/long");
                return 1;       
                }

                
        victim = present(arg, environment(me));

        if (rider ==0) return notify_fail("û����ѽ��\n");
        if (!living(victim)) return notify_fail("����������\n");

        message_vision(HIY "$N����һ�ƣ���$n��"NOR HIM"С����"NOR HIY"��������������\n"NOR, me, victim);

                rider = 0;
        victim->delete_leader(); 
        victim->delete_temp("apply/short");
        victim->delete_temp("apply/long");
        
        return 1;
}
