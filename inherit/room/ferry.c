// Code of ShenZhou
// /inherit/room/an.c
// cleansword 2 / 96
// by aln 4 / 98

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();

void setup()
{
        object room;

        ::setup();

        if( room = find_object(this_object()->query("boat")) )
        room->delete("yell_trigger");
}

void init()
{
        add_action("do_yell", "yell");
}

int do_yell(string arg)
{
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg == "boat" ) arg = "����";

        if( (int)this_player()->query("age") < 16 )
                message_vision("$Nʹ�����̵���������һ������" + 
                        arg + "��\n", this_player());
        else if( (int)this_player()->query("neili") > 500 )
                message_vision("$N���˿�����һ����" + arg + 
                        "������������ƽ�͵�ԶԶ��"
                        "�˳�ȥ��\n", this_player());
        else    message_vision("$N������������Хһ������" + arg + 
                        "����\n", this_player());

        if( arg == "����") {
                check_trigger();
                return 1;
        } else  message_vision(this_object()->query("name") + "����ԶԶ����һ���������" + arg +
                        "��������\n", this_player());

        return 1;
}

void check_trigger()
{
        object room;
        string myboat;

        if( this_object()->query("exits/enter") ) {
                message("vision", "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n",
                        this_object());
                return;
        }

        if( !(room = find_object(myboat = this_object()->query("boat"))) )
                room = load_object(myboat);

        if( !(room = find_object(myboat)) ) {
                message("vision", "ERROR: boat not found\n", this_object() );
                return;
        }

        if( room->query("yell_trigger") ) {
                message("vision", "ֻ����" + this_object()->query("name") + "�������������������"
                        "�����æ���š�����\n", this_object() );
                return;
        }

        room->set("yell_trigger", 1);
        this_object()->set("exits/enter", myboat);
        room->set("exits/out", base_name(this_object()));

        message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
                "����ϵ̰����Ա�˿�\n���¡�\n", this_object() );
        message("vision", "������һ��̤�Ű���ϵ̰����γ�һ������"
                "�Ľ��ݡ�\n", room);

        remove_call_out("on_board");
        call_out("on_board", 15);
}

void on_board()
{
        object room;

        if( !this_object()->query("exits/enter") ) 
                return;

        message("vision", "������̤�Ű��������������һ�㣬������" + this_object()->query("name") + "��ʻȥ��\n", this_object() );

        if( room = find_object(this_object()->query("boat")) ) {
                room->delete("exits/out");
                message("vision", "������̤�Ű���������˵��һ��������ඡ���"
                        "���һ�㣬������\n" + this_object()->query("name") + "��ʻȥ��\n", room );
        }

        this_object()->delete("exits/enter");

        remove_call_out("arrive");
        call_out("arrive", 20);
}

void arrive()
{
        object room;
        string myboat = this_object()->query("boat");
        string myopp = this_object()->query("opposite");

        if( room = find_object(myboat) ) {
                room->set("exits/out", myopp);
                message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
                        "���ϵ̰���\n", room );
        }

/*
        if( !(room = find_object(myopp)) )
                room = load_object(myopp);

        if( room = find_object(myopp) ) {
                room->set("exits/enter", myboat);
                message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
                        "����ϵ̰����Ա�˿�\n���¡�\n", room);
        }
*/       

        remove_call_out("close_passage");
        call_out("close_passage", 20);
}

void close_passage()
{
        object room;

        if( room = find_object(this_object()->query("boat")) ) {
                room->delete("exits/out");
                message("vision", "������̤�Ű����������ѱ���ʻ��" + this_object()->query("name") + "�ġ�\n", room);
                room->delete("yell_trigger");
        }

/*
        if( room = find_object(this_object()->query("opposite")) ) {
                room->delete("exits/enter");
                message("vision", "������̤�Ű��������������һ�㣬������" + this_object()->query("name") + "��ʻȥ��\n", room);
        }
*/
}
