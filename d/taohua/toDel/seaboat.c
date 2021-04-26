// Code of ShenZhou
// /d/shenlong/seaboat.xkx.c
// by ALN 10 / 97
// i will add more and more things
//modified by Kane

#include <ansi.h>
inherit ROOM;

string long_desc();
void do_ready();
void do_drop();
void reset();

void create()
{
        set("short", "����");
        set("long", (: long_desc :));
        set("invalid_startroom", 1);

        set("cost", 5);
        set("outdoors", "taohua");

        setup();
}

string long_desc()
{
        string desc;

        desc ="����һ�Һ���ͨ���洬������ˮ�ְ�Ū�ŷ��񣬸ݽ����������ʹ�βľ�档\n";
        desc += "����ָ����������ĺ��У�(1)start, (2)stop, (3)go, (4)lookout, (5)locate��\n\n";

        if( !query("exits/out") )
                switch((int)query_temp("navigate/weather")) {
                        case 1: desc += BLU"�����ͮ���ܲ���ֻ�м�ֻ��Ÿ���ڷ���չ�ᣬ��������ҡ�β��ѣ���е���\n�����㲻�ȡ�\n"NOR; break;
                        case 2: desc += BLU"������ӿ���ȣ����ɸߵľ�����ɽ�����Ƶ�ѹ������ʱ���п��ܽ����Ʒ�����\nʱ�����ò�������ס���ˣ������亣��\n"NOR; break;
                        default: desc += BLU"�����������ĺ��棬��������������ᴵ��������һ����һ�����ô������\n"NOR;  break;
                }
        return desc;
}

void init()
{
        add_action("do_start", "start");
        add_action("do_go", "go");
        add_action("do_stop", "stop");
        add_action("do_lookout", "lookout");
        add_action("do_locate", "locate");
        add_action("do_start", "1");
        add_action("do_go", "3");
        add_action("do_stop", "2");
        add_action("do_lookout", "4");
        add_action("do_locate", "5");
}

int do_start()
{
        mixed inv;
        object shipside, me = this_player();

        inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
        if( sizeof(inv) > 0 )
                return notify_fail("����ô����һ�㽭����ض�������\n");

        if( !query("exits/out") )
                return notify_fail("���Ѿ������ˡ�\n");

        if( !(shipside = find_object(query("exits/out"))) )
                shipside = load_object(query("exits/out"));

        switch((string)shipside->query("short")) {
                case "��ɽ":
                        set_temp("navigate/locx", 0);
                        set_temp("navigate/locy", 0);
                        break;
                case "����":
                        set_temp("navigate/locx", 35);
                        set_temp("navigate/locy", 35);
                        break;
        	case "��̲":
                        set_temp("navigate/locx", 35);
                        set_temp("navigate/locy", 35);
                        break;
	}

        message("vision", "�洬���˰���ʻ��ãã�Ĵ󺣡�\n", shipside);
        shipside->delete("exits/enter");

	message_vision("$N���һ���������������Ǵ������˰���\n", me);
        delete("exits/out");

        call_out("shipweather", 1);
        call_out("navigate", 1);
        set_temp("navigate/control", 1);

        return 1;
}

int navigate()
{
        object dest, *inv, *invofusr;
        string dir;
        int i, m, locx, locy, step;

        if( !random(40) && !query("exist/out")
        &&  query_temp("navigate/weather") == 2 ) {
                tell_room(this_object(), HIR"\nͻȻ�����������һ������ͷ��ˣ�\n\n"NOR);
                do_drop();
                return 1;
        }

	if( query_temp("navigate/locx") > 100 + random(50)
	|| query_temp("navigate/locy") > 100 + random(50) ){
                tell_room(this_object(), HIR"\nͻȻ�����������һ������ͷ��ˣ�\n\n"NOR);
                do_drop();
                return 1;
	}

        if( !(dir = (string)query_temp("navigate/dir")) ) {
                if( !random(40) ) {
                        add_temp("navigate/wait", 1);
                        if( query_temp("navigate/wait") > 5 ) {
                                tell_room(this_object(), "�����ǰѴ�Ҷ��ӽ��˺��\n");
                                do_drop();
                                return 1;
                        }
                        tell_room(this_object(),"ˮ����������������������\n");
                }                        
                call_out("navigate", 1);
                return 1;
        }       

	step = 1 + random(2);
        switch(dir) {
                case "��":
                        add_temp("navigate/locx", step);
                        break;
                case "��":
                        add_temp("navigate/locy", -step);
                        break;
                case "��":
                        add_temp("navigate/locx", -step);
                        break;
		case "��":
                        add_temp("navigate/locy", step);
                        break;
                default:
                        call_out("navigate", 1);
                        return 1;
        }

        locx = query_temp("navigate/locx");
        if( locx < 0 ) {
                tell_room(this_object(),"��ֻ������һ�������ƺ��Ѿ�������½�ء�\n");
                set("exits/out", __DIR__"zhoushan");

                delete_temp("navigate");
                call_out("do_ready", 20 + random(10));

                dest = find_object(__DIR__"zhoushan");
                dest->set("exits/enter", __DIR__"seaboat");
                message("vision", "һ���洬ʻ�˹�����\n", dest);
                return 1;
        }

        locy = query_temp("navigate/locy");
        if( locx >= 38 && locx <= 43 
	&&  locy >= 38 && locy <=43 ) {
                tell_room(this_object(),"����˵�����һ������������ϰ��ɣ��ҿɲ�Ը�������ط����������\n");
                set("exits/out", __DIR__"haitan");

                delete_temp("navigate");
                call_out("do_ready", 20 + random(10));

                  dest = find_object(__DIR__"haitan");
//                dest->set("exits/enter", __DIR__"seaboat");
//                message("vision", "һ���洬ʻ�˹�����\n", dest);
		tell_room(dest, "һ���洬ʻ�˹�����\n");
                return 1;
        }

	if( !random(3) )
                tell_room(this_object(), "������" + dir + "����ǰ����\n");
        call_out("navigate", 1);

        return 1;
}

int do_go(string arg)
{
        string dir;
        object me = this_player();
        mixed inv;

        if( query("exits/out") )
                return notify_fail("����û���ء�\n");

        if( !query_temp("navigate/control") ) {
                call_out("shipweather", 1);
                call_out("navigate", 1);
                set_temp("navigate/control", 1);
        }

        inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
        if( sizeof(inv) > 0 )
                return notify_fail("����ô����һ�㽭����ض�������\n");

        switch(arg) {
                case "e":
                case "east": 
                        dir = "��";
                        break;
                case "s": 
                case "south": 
                        dir = "��";
                        break;
                case "w": 
                case "west": 
                        dir = "��";
                        break;
                case "n": 
                case "north": 
                        dir = "��";
                        break;
                default:
                        return notify_fail("��Ҫ�����ĸ����򿪣�\n");
        }

        set_temp("navigate/dir", dir);
        message_vision("$N�Դ���ʾ�⳯" + dir + "����\n", me);
        return 1;
}

int do_stop()
{
        object me = this_player();
        mixed inv;

        inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
        if( sizeof(inv) > 0 )
                return notify_fail("����ô����һ�㽭����ض�������\n");

        if( !query_temp("navigate/dir") )
                return notify_fail("���Ѿ�ͣ�ˡ�\n");

        message_vision("$N�д����ǰѴ�ͣһͣ��\n", me);
        delete_temp("navigate/dir");

        return 1;
}

int do_lookout()
{
        string dir;
        int locx, locy;

        if( query("exits/out") ) {
                tell_object(this_player(), "����û���ء�\n");
                return 1;
        }

        locx = (int)query_temp("navigate/locx");

        if( locx < 0 ) {
                tell_object(this_player(), "���Ѿ��ڴ�½�����ˡ�\n");
                return 1;
        }

        if( locx < 6 ) {
                tell_object(this_player(), "�㼫ĿԶ�����������治Զ�����Ǵ�½��\n");
                return 1;
        }

        locy = (int)query_temp("navigate/locy");

        if( locx >= 38 && locx <= 43
	&& locy >=38 && locy >= 43 ) {
                tell_object(this_player(), "���Ѿ����һ��������ˡ�\n");
                return 1;
        }

        if( (locy > 20 && locy < 40) && (locx > 20 && locx < 40) )
                dir = "����";
        else if( (locy > 20 && locy < 40) && locx == 40 )
                dir = "��";
        else if( (locy > 20 && locy < 40) && (locx > 40 && locx < 60) )
                dir = "����";
        else if( locy == 40 && (locx > 20 && locx < 40) )
                dir = "��";
        else if( locy == 40 && (locx > 40 && locx < 60) )
                dir = "��";
        else if( (locy > 40 && locy < 60) && (locx > 20 && locx < 40) )
                dir = "����";
        else if( (locy > 40 && locy < 60) && locx == 40 )
                dir = "��";
        else if( (locy > 40 && locy < 60) && (locx > 40 && locx < 60) )
                dir = "����";

        if( dir )
                tell_object(this_player(), "�㼫ĿԶ���������һ�������" +dir + "����\n");
        else    tell_object(this_player(), "�㼫ĿԶ����ֻ����ãã��\n");

        return 1;
}

int do_locate()
{
        string dir;
        int locx, locy;

        if( query("exits/out") ) {
                tell_object(this_player(), "����û���ء�\n");
                return 1;
        }

        locx = (int)query_temp("navigate/locx");

        if( locx < 0 ) {
                tell_object(this_player(), "���Ѿ��ڴ�½�����ˡ�\n");
                return 1;
        }

        locy = (int)query_temp("navigate/locy");

        if( locx >= 38 && locx <= 43 
	&& locy >= 38 && locy <=43 ) {
                tell_object(this_player(), "���Ѿ����һ��������ˡ�\n");
                return 1;
        }

        locx = (locx * 9 + random(locx * 2 ))/10;
        locy = (locy * 9 + random(locy * 2 ))/10;

        if( locy > 0 ) 
                dir = "��" + chinese_number(locx) + "����" + "��Լ" + chinese_number(locy) + "����";
        else if( locy < 0 )
                dir = "��Լ" + chinese_number(locx) + "����" + "��Լ" + chinese_number(-locy) + "����";
        else    dir = "����Լ" + chinese_number(locx) + "����";

        tell_object(this_player(), "����������ɽ" + dir + "����\n");

        return 1;
}

private is_owner(object ob, object me)
{
        if( living(ob) && userp(ob) && ob != me
        &&  (int)ob->query("combat_exp") > (int)me->query("combat_exp") )
                return 1;

        return 0;
}

void shipweather()
{
        if( !filter_array(all_inventory(this_object()), (:userp:)) )
                return;

        if( query("exits/out") ) return;
//        if( !mapp(query_temp("navigate")) ) return;

        if( !query_temp("navigate/weather") ) {
                if( !random(6) ) {
                        set_temp("navigate/weather", 1);
                        remove_call_out("niceweather");
                        call_out("niceweather", 5 + random(10));
                } else  if( !random(24) ) {
                        set_temp("navigate/weather", 2);
                        remove_call_out("niceweather");
                        call_out("niceweather", 5 + random(10));
                }
        }

        if( !query_temp("navigate/weather") )
                call_out("shipweather", 1);
}

void niceweather()
{
        set_temp("navigate/weather", 0);
        call_out("shipweather", 1);
}

void do_drop()
{
        object *inv, *invofusr;
        int i, m;

        inv = all_inventory(this_object());
        for( i = 0; i < sizeof(inv); i++ ) {
                if( userp(inv[i]) ) {
                        inv[i]->unconcious();
                        invofusr = all_inventory(inv[i]);
                        for(m = 0; m < sizeof(invofusr); m++)
                                destruct(invofusr[m]);
                        if( random(8) == 1 )
                                inv[i]->move("/d/taohua/haitan");
                        else    inv[i]->move("/d/taohua/zhoushan");
                        message("vision",
                        "�㷢��һ������ˮ���ܵļһﱻ��ˮ���ϰ��������ɵ��߽�һ����ԭ����" + inv[i]->query("name") +"��\n", environment(inv[i]), ({inv[i]}));
                } else  destruct(inv[i]);
        }

        delete_temp("navigate");
        delete_temp("trigger");
}

void do_ready()
{
        object shipside;

        if( !query_temp("trigger") || !query("exits/out") )
                return;

        if( !(shipside = find_object(query("exits/out"))) )
                shipside = load_object(query("exits/out"));

        switch((string)shipside->query("short")) {
                case "��ɽ":
                        set_temp("navigate/locx", 0);
                        set_temp("navigate/locy", 0);
                        break;
                case "����":
                        set_temp("navigate/locx", 35);
                        set_temp("navigate/locy", 35);
                        break;
        	case "��̲":
                        set_temp("navigate/locx", 35);
                        set_temp("navigate/locy", 35);
                        break;
	}

        message("vision", "�洬���˰���ʻ��ãã�Ĵ󺣡�\n", shipside);
        shipside->delete("exits/enter");

        delete_temp("trigger");
        delete("exits/out");
        message("vision", "��������ê�﷫�����Ǵ������˰���\n",this_object());
}

void reset()
{
        object shipside;

        ::reset();

        if( !(shipside = find_object(__DIR__"zhoushan")) )
                shipside = load_object(__DIR__"zhoushan");

        if( shipside->query("exits/enter") )
                shipside->delete("exits/enter");

        if( !(shipside = find_object(__DIR__"harbor")) )
                shipside = load_object(__DIR__"harbor");

        if( shipside->query("exits/enter") )
                shipside->delete("exits/enter");
}
