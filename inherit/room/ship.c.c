// Code of ShenZhou
// ship.c ����
// by ALN@XKX
// modified by sdong to fix boat out bug, 8/2/1999

inherit F_CLEAN_UP;
inherit ROOM;

#include <ansi.h>
#include "/clone/ship/harbor.h"
#include "/clone/ship/seashape.h"

string long_desc();
void do_ready();
void do_drop();
int is_owner(object, object);
void time_out();

void reset() // set ships to no_reset
{}

string long_desc()
{
		  string desc;

		  desc = "����һ�Һ���ͨ���洬����������Ū�ŷ��񣬸ݽ����������ʹ�βľ�档\n";
		  desc += "����ָ����������ĺ��У�(1)start, (2)stop, (3)go, (4)lookout, (5)locate��\n\n";

		  if( !this_object()->query("exits/out") )
					 switch((int)this_object()->query_temp("navigate/weather")) {
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
		  call_out( "time_out", 500+random(600) );
}

void time_out()
{
	 tell_room(this_object(), HIR"\nͻȻ�����������һ������ͷ��ˣ�\n\n"NOR);
	 do_drop();
}

int valid_leave(object me, string dir)
{
		  object *inv, harbor;

		  if( dir == "out" ) {
					 inv = all_inventory(this_object());
					 for(int i = 0; i < sizeof(inv); i++) {
								if( inv[i] != this_player() && userp(inv[i]) )
								return ::valid_leave(me, dir);
					 }

					 remove_call_out("do_ready");
					 call_out("do_ready", 5);
		  }

		  return ::valid_leave(me, dir);
}

int do_start()
{
		  mixed inv;
		  object harbor, me = this_player();
		  string filename, argg;
		  int num;

		  inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
		  if( sizeof(inv) > 0 )
					 return notify_fail("����ô����һ�㽭����ض�������\n");

        if( !stringp(filename = this_object()->query("exits/out")) )
					 return notify_fail("���Ѿ������ˡ�\n");

        if( !(harbor = find_object(filename)) )
                harbor = load_object(filename);

		  message("vision", "�洬���˰���ʻ��ãã�Ĵ󺣡�\n", harbor);
		  filename = base_name(this_object());
		  if( sscanf(filename, "%s%d", argg, num) == 2 )
		  harbor->delete("exits/enter" + num);

		  message_vision("$N���һ���������������Ǵ������˰���\n", me);
		  this_object()->delete("exits/out");

		  this_object()->delete_temp("navigate");

		  this_object()->set_temp("navigate/locx", (int)harbor->query("navigate/locx"));
		  this_object()->set_temp("navigate/locy", (int)harbor->query("navigate/locy"));

		  remove_call_out("shipweather");
		  call_out("shipweather", 1);
		  remove_call_out("navigate");
		  call_out("navigate", 2);
		  remove_call_out("do_ready");

		  return 1;
}

int navigate()
{
		  object harbor;
		  string dir, *filenames, filename, argg;
		  int i, num, locx, locy, *pos, drop_factor;

		  locx = (int)this_object()->query_temp("navigate/locx");
		  locy = (int)this_object()->query_temp("navigate/locy");
	if( locx > 50 || locy > 50 )
		drop_factor = 1;
	else drop_factor = 0;

		  remove_call_out("navigate");

		  for(i = 0; i < sizeof(jiaos); i++) {
					 pos = jiaos[i];
					 if( this_object()->query_temp("navigate/locx") == pos[0]+random(3)-1 && this_object()->query_temp("navigate/locy") == pos[1]+random(3)-1 ) {
								tell_room(this_object(), HIR"ͻȻ�䴬���ҵ�����һ�£������ˣ������ˣ�\n\n"NOR);
								do_drop();
								return 1;
					 }
		  }

		  if( !random(100) && !this_object()->query("exist/out")
		  &&  this_object()->query_temp("navigate/weather") == 2
	&& drop_factor) {
					 tell_room(this_object(), HIR"\nͻȻ�����������һ������ͷ��ˣ�\n\n"NOR);
					 do_drop();
					 return 1;
		  }

		  if( !random(40) && !this_object()->query("exist/out") ) {
		switch(random(10)) {
		case 0 : /* monster ����*/
			break;
		case 1 : /* treasure �Ʊ�*/
			break;
		case 2 : /* corsair ����*/
			break;
		case 3 :
			tell_room(this_object(), HIC
			"�㿴��Φ�����������ɫ�Ĺ⣬�ۣ��񼣣�����\n"NOR);
			break;
					 case 4 :
								tell_room(this_object(), HIW
			"����������һ���ƾɵĴ󴬿��˹�����һ�������ʧ�ˣ����ϴ���������̾Ϣ����\n"+
			"����ϡ�ǵô����м������֣�Titanic��������\n"NOR);
								break;
					 case 5 :
								tell_room(this_object(), HIR
			"�㿴��һֻȼ���ŵĴ����򴬳��������⣬Ҫײ���ˣ�����\n"NOR);
								break;
					 case 6 :
								tell_room(this_object(), HIM
			"�����ϴ���һ������ĸ��������ʱ��һ�ְ��಻ס���º��ĳ嶯������\n"NOR);
								break;
					 case 7 :
								tell_room(this_object(), HIG
			"��ͻȻ���ֺ�����һֻ��ɫ���۾��������㣬��һ����Ͳ����ˣ����ŵû겻���壡����\n"NOR);
								break;
					 case 8 :
								tell_room(this_object(), HIY
			"�㿴��Զ��һ��������β��������ŮԾ�����棬���磡�������֣�����\n"NOR);
								break;
		case 9 :
			tell_room(this_object(), HIG
			"����ǰһ��������ӳ��һƬ����Ī����״�Ĺ�ʣ�"+HIM"�����������׵Ĺ�ɫ���ںڰ���\n"+
			"���������"+YEL"��Ƭ�Ȼ�֮��"+MAG"����˿˿���ϣ�������ɫ������������ɫ֮�У������һ\n"+
			"����"+HIY"��⡢"+HIB"���⡢"+HIG"�̹⡢"+HIR"��⡣\n"NOR);
			break;
		}
	}

		  if( !stringp(dir = this_object()->query_temp("navigate/dir")) ) {
					 if( !random(100) ) {
                        this_object()->add_temp("navigate/wait", 1);
                        if( this_object()->query_temp("navigate/wait") > 5 ) {
                                tell_room(this_object(), "�����ǰѴ�Ҷ��ӽ��˺��\n");
                                do_drop();
                                return 1;
                        }
                        tell_room(this_object(), "�����ǲ��ͷ���˵���㵽���߲��߰���\n");
                }                   
                call_out("navigate", 2);
                return 1;
        }

        if( this_object()->query_temp("navigate/wait") )
        this_object()->delete_temp("navigate/wait");

		  switch(dir) {
                case "��":
                        this_object()->add_temp("navigate/locx", 1);
                        break;
                case "��":
                        this_object()->add_temp("navigate/locy", -1);
								break;
					 case "��":
                        this_object()->add_temp("navigate/locx", -1);
                        break;
		case "��":
                        this_object()->add_temp("navigate/locy", 1);
                        break;
                default:
                        call_out("navigate", 2);
                        return 1;
        }

        locx = this_object()->query_temp("navigate/locx");
        locy = this_object()->query_temp("navigate/locy");

		  if( locx < 1 ) {
                filenames = keys(harbors);
	        for(i = 0; i < sizeof(filenames); i++) {
                        if( locy == harbors[filenames[i]] ) break;
                }

                if( i >= sizeof(filenames) ) {
                        tell_room(this_object(), "����˵��̾��Ư����һ�ĵ������ǸϽ��뿪�ɡ�\n");
                        this_object()->delete_temp("navigate/dir");
                        call_out("navigate", 2);
                        return 1;
                }

                if( !(harbor = find_object(filenames[i])) )
                        harbor = load_object(filenames[i]);

                tell_room(this_object(), "����˵����" + harbor->query("short") + "�������ϰ��ɡ���\n");

					 this_object()->set("exits/out", filenames[i]);
                this_object()->delete_temp("navigate");
                remove_call_out("shipweather");
                remove_call_out("do_ready");
                call_out("do_ready", 20);
 
					 filename = base_name(this_object());
					 if( sscanf(filename, "%s%d", argg, num) == 2 )
                harbor->set("exits/enter" + num, filename);
                message("vision", "һ���洬ʻ�˹�����\n", harbor);
                return 1;
        }

        filenames = keys(islands);
        for(i = 0; i < sizeof(filenames); i++) {
                pos = islands[filenames[i]];
                if( locx == pos[0] && locy == pos[1] ) {
                this_object()->set("exits/out", filenames[i]);
                this_object()->delete_temp("navigate");
                remove_call_out("shipweather");
                remove_call_out("do_ready");
					 call_out("do_ready", 20);

                if( !(harbor = find_object(filenames[i])) )
                        harbor = load_object(filenames[i]);
                
                filename = base_name(this_object());
                if( sscanf(filename, "%s%d", argg, num) == 2 )
                harbor->set("exits/enter" + num, filename); 

                tell_room(this_object(), "����˵����" + harbor->query("island") + "�������ϰ��ɡ���\n");
                message("vision", "һ���洬ʻ�˹�����\n", harbor);
                return 1;
	        }
	}

	if( !random(3) )
                tell_room(this_object(), "������" + dir + "����ǰ����\n");
        call_out("navigate", 2);

        return 1;
}

int do_go(string arg)
{
		  string dir;
		  object me = this_player();
        mixed inv;

        if( this_object()->query("exits/out") )
                return notify_fail("����û���ء�\n");

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

        this_object()->set_temp("navigate/dir", dir);
		  message_vision("$N�Դ���˵�����ϴ��볯" + dir + "����\n", me);
        return 1;
}

int do_stop()
{
		  object me = this_player();
		  mixed inv;

        inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
        if( sizeof(inv) > 0 )
                return notify_fail("����ô����һ�㽭����ض�������\n");

        if( !this_object()->query_temp("navigate/dir") )
                return notify_fail("���Ѿ�ͣ�ˡ�\n");

        message_vision("$N�д����ǰѴ�ͣһͣ��\n", me);
        this_object()->delete_temp("navigate/dir");

        return 1;
}

int do_lookout()
{
        object harbor;
        string dir, *filenames;
        int i, m, locx, locy, tot, dist, *pos;

        if( this_object()->query("exits/out") ) {
                tell_object(this_player(), "����û���ء�\n");
                return 1;
        }

        locx = (int)this_object()->query_temp("navigate/locx");

        if( locx <= 0 ) {
                tell_object(this_player(), "���Ѿ��ڰ����ˡ�\n");
                return 1;
        }

        if( locx < 6 ) {
                tell_object(this_player(), "�㼫ĿԶ�����������治Զ�����ǰ��ߡ�\n");
                return 1;
        }

		  locy = (int)this_object()->query_temp("navigate/locy");

        filenames = keys(islands);
        for(i = 0; i < sizeof(filenames); i++) {
                pos = islands[filenames[i]];
                if( !(harbor = find_object(filenames[i])) )
                        harbor = load_object(filenames[i]);
                if( locx == pos[0] && locy == pos[1] ) {
                tell_object(this_player(), "���Ѿ���" +  harbor->query("island") + "�����ˡ�\n");
                return 1;
                }
        }

        tot = 10000000;
        m = 10000;
		  for(i = 0; i < sizeof(filenames); i++) {
                pos = islands[filenames[i]];
                dist = (locx - pos[0]) * (locx - pos[0]) +
                       (locy - pos[1]) * (locy - pos[1]);
                if( dist < tot ) { tot = dist; m = i; }
        }

        if( tot > 72 ) {
                tell_object(this_player(), "�㼫ĿԶ����ֻ����ãã��\n");
                return 1;
        }

        pos = islands[filenames[m]];

        if( (locy >= pos[1] - 6 && locy < pos[1])
            && (locx >= pos[0] - 6 && locx < pos[0] ) )
                dir = "����";
        else if( (locy >= pos[1] - 6 && locy < pos[1]) && locx == pos[0] )
					 dir = "��";
        else if( (locy >= pos[1] - 6 && locy < pos[1])
            && (locx > pos[0] && locx <= pos[0] + 6) )
                dir = "����";
        else if( locy == pos[1] && (locx >= pos[0] - 6 && locx < pos[0]) )
                dir = "��";
		  else if( locy == pos[1] && (locx > pos[0] && locx <= pos[0] + 6) )
					 dir = "��";
        else if( (locy > pos[1] && locy <= pos[1] + 6)
            && (locx >= pos[0] - 6 && locx < pos[0]) )
                dir = "����";
        else if( (locy > pos[1] && locy <= pos[1] + 6) && locx == pos[0] )
                dir = "��";
        else if( (locy > pos[1] && locy <= pos[1] + 6)
            && (locx > pos[0] && locx <= pos[0] + 6) )
                dir = "����";

        if( dir ) {
                if( !(harbor = find_object(filenames[m])) )
                        harbor = load_object(filenames[m]);
                tell_object(this_player(), "�㼫ĿԶ��������" + dir + "����" + harbor->query("shape") + "\n");
		  } else  tell_object(this_player(), "�㼫ĿԶ����ֻ����ãã��\n");

        return 1;
}

int do_locate()
{
        string dir, *filenames;
        int tot, dist, m, i, locx, locy;
        object harbor;

        if( this_object()->query("exits/out") ) {
                tell_object(this_player(), "����û���ء�\n");
                return 1;
        }

        locx = (int)this_object()->query_temp("navigate/locx");
        locy = (int)this_object()->query_temp("navigate/locy");

        tot = 10000000;
        m = 10000;
        filenames = keys(harbors);
        for(i = 0; i < sizeof(filenames); i++) {
                dist = locx * locx + (locy - harbors[filenames[i]]) * 
							  (locy - harbors[filenames[i]]);
					 if( dist < tot ) { tot = dist; m = i; }
        }

        locy = locy - harbors[filenames[m]];
        if( !wizardp(this_player()) ) {
        locx = (locx * 9 + random(2 * locx))/10;
        locy = (locy * 9 + random(2 * locy))/10;
        }

        if( !(harbor = find_object(filenames[m])) )
                harbor = load_object(filenames[m]);

        if( locx < 1 ) {
                if( locy > 0 ) 
					 dir = "����Լ" + chinese_number(locy) + "����";
					 else if( locy < 0 )
					 dir = "����Լ" + chinese_number(-locy) + "����";
					 else dir = "";
		  } else {
					 if( locy > 0 )
					 dir = "��Լ" + chinese_number(locx) + "����" + "��Լ" + chinese_number(locy) + "����";
					 else if( locy < 0 )
					 dir = "��Լ" + chinese_number(locx) + "����" + "��Լ" + chinese_number(-locy) + "����";
					 else
					 dir = "����Լ" + chinese_number(locx) + "����";
		  }

		  tell_object(this_player(), "��������" + harbor->query("short") + dir + "��\n");

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

        if(this_object()-> query("exits/out") ) return;

        if( !this_object()->query_temp("navigate/weather") ) {
                if( !random(6) ) {
                        this_object()->set_temp("navigate/weather", 1);
                        remove_call_out("niceweather");
                        call_out("niceweather", 5 + random(10));
					 } else  if( !random(24) ) {
                        this_object()->set_temp("navigate/weather", 2);
                        remove_call_out("niceweather");
                        call_out("niceweather", 5 + random(10));
                }
        }

        if( !this_object()->query_temp("navigate/weather") )
                call_out("shipweather", 1);
}

void niceweather()
{
        this_object()->set_temp("navigate/weather", 0);
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
								for(m = 0; m < sizeof(invofusr); m++) {
			if(invofusr[m]->query("id") == "tie lian")
										  continue;
								else    destruct(invofusr[m]);
								}
								inv[i]->move(keys(harbors)[random(sizeof(harbors))]);
								message("vision",
								"�㷢��һ������ˮ���ܵļһﱻ��ˮ���ϰ��������ɵ��߽�һ����ԭ����" + inv[i]->query("name") +"��\n", environment(inv[i]), ({inv[i]}));
					 } else  destruct(inv[i]);
		  }

		  remove_call_out("shipweather");
		  this_object()->delete_temp("navigate");
		  this_object()->delete_temp("trigger");
}

void do_ready()
{
		  object harbor, *inv, carbin;
		  string filename, argg;
		  int i, num;

        if( !this_object()->query_temp("trigger") 
         || !stringp(filename = this_object()->query("exits/out")) )
                return;

        if( member_array(filename, wildharbors) != -1 ) {
        if( !this_object()->query_temp("waited") ) {
                this_object()->set_temp("waited", 1);
					 remove_call_out("do_ready");
					 call_out("do_ready", 100);
                return;
        } else  this_object()->delete_temp("waited");
        }

        if( !(harbor = find_object(filename)) )
                harbor = load_object(filename);

        inv = all_inventory(this_object());
        for(i = 0; i < sizeof(inv); i++) {
                if( userp(inv[i]) ) {
                        inv[i]->move(harbor);
                        message_vision("ֻ�����飡����һ����$N���������´����Ǳ�������\n", inv[i]);
                }
        }

        if( stringp(filename = this_object()->query("exits/down")) ) {
        if( carbin = find_object(filename) ) {
        inv = all_inventory(carbin);
        for(i = 0; i < sizeof(inv); i++) {
                if( userp(inv[i]) ) {
                        inv[i]->move(harbor);
                        message_vision("ֻ�����飡����һ����$N���������´����Ǳ�������\n", inv[i]);
                }
        }
        }
        }

        message("vision", "�洬���˰���ʻ��ãã�Ĵ󺣡�\n", harbor);
        filename = base_name(this_object());
        if( sscanf(filename, "%s%d", argg, num) == 2 )
        harbor->delete("exits/enter" + num);

        this_object()->delete_temp("trigger");
        this_object()->delete("exits/out");

        message("vision", "��������ê�﷫�����Ǵ������˰���\n", this_object());
}

