// Code of ShenZhou
// harbor.c
// by ALN@XKX

inherit F_CLEAN_UP;
inherit ROOM;

#define SHIP      "/clone/ship/seaboat"
#define SHIPS     "/clone/ship/"
#define SHIPNAME  "seaboat"
#include "/clone/ship/harbor.h";

void setup()
{
        object ship;
        string *files;

        ::setup();

        files = get_dir(SHIPS);
        for(int i = 0; i < sizeof(files); i++) {
                if( strsrch(files[i], SHIPNAME) == 0 ) {
                        files[i] = SHIPS + files[i];
                        if( ship = find_object(files[i]) )
                                ship->delete("yell_trigger");
               } 
        }
}

void init()
{
        add_action("do_yell", "yell");
}

int do_yell(string arg)
{
        object ship, harbor;
        string filename, *files;
        int i, tot;

        if( !arg || arg != "chuan" )
                return notify_fail("��󺰴�еĸ�ʲô��\n");

        files = get_dir(SHIPS);
        tot = 0;
        for(i = 0; i < sizeof(files); i++) {
                if( strsrch(files[i], SHIPNAME) == 0 ) tot++;
        }

        for(i = 1; i < tot + 1; i++) {
                if( this_object()->query("exits/enter" + i) )
                return notify_fail("����ˣ���ô���۾�û��������\n");
        }

        if( member_array(base_name(this_object()), wildharbors) != -1 )
                return notify_fail("�����ǻĵ��������д�������\n");

        for(i = 1; i < tot + 1; i++) {
                if( !(ship = find_object(SHIP + i)) )
                ship = load_object(SHIP + i);

                if( !ship->query_temp("trigger") )  
                break;
        }

        if( i > tot )
                return notify_fail("�㺰�˰��죬Ҳû��һ����������\n");

        if( stringp(filename = ship->query("exits/out")) ) {
                if( !(harbor = find_object(filename)) )
                harbor = load_object(filename);

                message("vision", "�洬���˰���ʻ��ãã�Ĵ󺣡�\n", harbor);
                harbor->delete("exits/enter" + i);
                ship->delete("exits/out");
        }

        ship->set_temp("trigger", 1);
        remove_call_out("do_ready");
        call_out("do_ready", 20, ship);

        this_object()->set("exits/enter" + i, base_name(ship));
        ship->set("exits/out", base_name(this_object()));

        if( (int)this_player()->query("age") < 16 )
                message_vision("$Nʹ�����̵���������һ���������ҡ�\n", this_player());
        else if( (int)this_player()->query("neili") > 500 )
                message_vision("$N���˿�����һ�������ҡ�����������ƽ�͵�ԶԶ���˳�ȥ��\n", this_player());
        else    message_vision("$N������������Хһ���������ң���\n", this_player()); 

        message("vision", "һ���洬Ӧ������ʻ�˹��������һ��̤�Ű����ɳ̲�ϡ�\n", this_object());

        return 1;
}

int valid_leave(object me, string dir)
{
        if( strsrch(dir, "enter") == 0 && !this_object()->query("navigate/locx") ) {
                switch (MONEY_D->player_pay(this_player(), 200)) {
                case 0:
                        return notify_fail("��⵰��һ�ߴ���ȥ��\n");
                case 2:
                        return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
                default:
                        remove_call_out("do_ready");
                        call_out("do_ready", 10);
                        break;
                }
        }

        return ::valid_leave(me, dir);
}

void do_ready(object ship)
{
        object *inv, carbin;
        string filename, argg;
        int i, num;

	if ( !objectp( ship ) ) return;
        if( !stringp(filename = ship->query("exits/out")) )  return;
        if( filename != base_name(this_object()) ) return;

        ship->delete_temp("trigger");
        ship->delete("exits/out");

        inv = all_inventory(ship);
        for(i = 0; i < sizeof(inv); i++) {
                if( userp(inv[i]) ) {
                        inv[i]->move(this_object());
                        message_vision("ֻ�����飡����һ����$N���������´����Ǳ�������\n", inv[i]);
                }
        }

        if( stringp(filename = ship->query("exits/down")) ) {
        if( carbin = find_object(filename) ) {
        inv = all_inventory(carbin);
        for(i = 0; i < sizeof(inv); i++) {
                if( userp(inv[i]) ) {
                        inv[i]->move(this_object());
                        message_vision("ֻ�����飡����һ����$N���������´����Ǳ�������\n", inv[i]);
                }
        }
        }
        }

        message("vision", "�����Ǵ��һ���������������Ǵ������˰���\n", ship);

        filename = base_name(ship);
        if( sscanf(filename, "%s%d", argg, num) == 2 )
        this_object()->delete("exits/enter" + num);
        message("vision", "�洬���˰���ʻ��ãã�Ĵ󺣡�\n", this_object());
}
