/* /kungfu/class/movie/ct.c
** �����н��ʴ�����
** created by yujie
** created in 11/2001
*/


inherit ROOM;

#define CAIPIAO "/kungfu/class/movie/obj/caipiao"
#define CPNUM "/data/movie/caipiao/cpnum"
#define CPSYS "/adm/single/cpsys"
#define GG "/data/movie/guanggao"

#include <ansi.h>
#include <inttostr.h>


nosave string answer;
nosave string title;
nosave string *in_movie;
nosave mapping question;
nosave string zhuti;
nosave int line;

void doing();
void start_answer();
string look_sign();
void end_answer();
void setblock(int pan);
void move_all();
void setall();
void deleteall();

int query_num();
void set_num(int);

void create()
{
        set("short", "ӰԺ����ӳ��");
        set("long", @LONG
���������ݵ��н��ʴ����ģ�ÿ��ʢ��Ľ��ն�����������зḻ��
�н��ʴ�����Ʒ���������ݲ�Ʊ�з��еĸ�����Ʊ����������
�п��������Ʒ��񣬻�ӭӻԾ�μӡ��м�����һ������ӣ�sign����
�����л�������Ϣ��
LONG
        );

        set("item_desc", ([
                "sign" : (: look_sign :),
        ]));

        set("exits", ([
                "out" : "/d/city/guangchang"
        ]));

        set("objects", ([
                __DIR__"npc/cpwaiter" : 1,
                __DIR__"npc/zhuchi" : 1,

        ]));

        set("no_fight", 1);
        set("no_steal", 1);
        set("answer_time",30);
        set("ppl_number",5);
        set("cost", 0);
        setup();
}

string look_sign()
{       string movie;
        if (!zhuti || zhuti == "")
                return "����û���н��������С�\n";

        movie = "�������ھ��������н�������\n���λ�������ǣ�\n\n\n\t\t"+HIW+zhuti+NOR+"\n\n";
	movie += "û��Ƥ�ұ����Ʊ������������Ʊ�е���ʱ�д�Ҫһ��Ƥ�ҡ�\n";
	movie += "���Ӯ�õĲ�Ʊ���Ա�����Ƥ�����ô����Ҳ���ᶪʧ�ˣ������Ὺ�������������ݲ�Ʊ�еĹ��档\n";
	movie += "\n\t\t\t\t------- �����ˣ�Yujie\n";
        return movie;
}

void move_all()
{       object ob = this_object();
        object *usrs;
        int i;

        usrs = all_inventory(ob);
        for(i=0; i<sizeof(usrs) ;i++ )
                if ( userp(usrs[i])) {usrs[i]->set_temp("block_msg/all",1);usrs[i]->move(ob);usrs[i]->delete_temp("block_msg/all");}
}

void setall()
{       object ob = this_object();
        object *usrs;
        int i;

        usrs = all_inventory(ob);
        for(i=0; i<sizeof(usrs) ;i++ )
                if ( userp(usrs[i])) usrs[i]->set("movie_answer",1);
}

void deleteall()
{       object ob = this_object();
        object *usrs;
        int i;

        usrs = all_inventory(ob);
        for(i=0; i<sizeof(usrs) ;i++ )
                if ( userp(usrs[i])) usrs[i]->delete("movie_answer");
}

void setblock(int pan)
{
        object me = this_object();
        object *users;
        int i;

        users = all_inventory(me);

        if (pan)
                for(i=0 ; i<sizeof(users) ; i++)
                        users[i]->set_temp("block_msg/all",1);
        else
                for(i=0 ; i<sizeof(users) ; i++)
                        users[i]->set_temp("block_msg/all",0);
}

int do_setline(string arg)
{
        int i;
        if (!wizardp(this_player()))
                return notify_fail("ֻ����ʦ�������ò��ŵ�������\n");

        if (!arg) return notify_fail("��Ҫ���õĲ����ǣ�\n");

        if ( sscanf(arg,"%d",i) == 1)
        {       line = i;
                write("����Ϊ"+chinese_number(i)+"�п�ʼ���š�\n");
        }else
                write("����ʧ�ܣ����������֡�\n");
        return 1;
}

int do_nowline(string arg)
{
        int time;
        if (!wizardp(this_player()))
                return notify_fail("ֻ����ʦ���������н�����ļ��ʱ�䡣\n");

        write("���ڵ������ǣ�"+chinese_number(line)+"��\n");
        return 1;
}



void init()
{       object me = this_player();

        remove_action("do_answer","answer");
        if ( me->query("movie_answer") )
                add_action("do_answer","answer");

        add_action("do_settime","settime");
        add_action("do_setnum","setnum");
        add_action("do_setline","setline");
        add_action("do_nowline","nowline");

        add_action("do_play","play");
        add_action("do_stop","stop");

}


int query_num()
{       string arg;
        int num;

        arg = read_file(CPNUM);

        if (sscanf(arg,"%d",num) == 1)
                return num;

        return 0;
}

void set_num(int num)
{
        string arg;

        arg = tostring(num);
        write_file(CPNUM,arg,1);
}

int do_settime(string arg)
{
        int time;

        if (!wizardp(this_player()))
                return notify_fail("ֻ����ʦ���������н�����ļ��ʱ�䡣\n");

        if (!arg) return notify_fail("��Ҫ���õĲ����ǣ�\n");

        if ( sscanf(arg,"%d",time) == 1)
        {       set("answer_time",time);
                write("����Ϊ"+chinese_number(time)+"���ֽ���һ���н�����\n");
        }else
                write("����ʧ�ܣ����������֡�\n");
        return 1;
}


int do_setnum(string arg)
{
        int num;
        if (!wizardp(this_player()))
                return notify_fail("ֻ����ʦ���������н�����ĵ���������\n");

        if (!arg) return notify_fail("��Ҫ���õĲ����ǣ�\n");

        if ( sscanf(arg,"%d",num) == 1)
        {       set("ppl_number",num);
                write("����Ϊ"+chinese_number(num)+"Ϊ������������������\n");
        }else
                write("����ʧ�ܣ����������֡�\n");
        return 1;
}


int do_play(string arg)
{
        object me = this_player();


        if ( !wizardp(me) )
                return notify_fail("ֻ����ʦ���ܾ����н�������\n");

        if (query("player_now"))
                return notify_fail("�����Ѿ��ھ��о����ˡ�\n");

        zhuti = arg;
        set("play_now",1);
        in_movie = explode(read_file(GG),"\n");
	line = 1;

        shout( HIG "���н����𡿣����ڿ�ʼ���������н���������ӭ��Ҵ�����㳡enter�볡�μӡ�\n"NOR);
        shout( HIG "���н����𡿣������н�����������ǣ�"+zhuti+"\n"NOR);
        write( HIG "���н����𡿣����ڿ�ʼ���������н���������ӭ��Ҵ�����㳡enter�볡�μӡ�\n"NOR);
        write( HIG "���н����𡿣������н�����������ǣ�"+zhuti+"\n"NOR);


        call_out("doing",1);

        return 1;
}

void doing()
{       string arg, msg;
        int time,num ,i,j;
        object *user;
        object me = this_object();
        object q_ob;

        time = query("answer_time");
        num  = query("ppl_number");

	if (line >= sizeof(in_movie) )
		line = 1;

        arg = in_movie[line];
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        arg = replace_string(arg, "$BLINK$", BLINK);
        arg = arg + "\n";
        arg = HIG"���岥��桿��"NOR + arg;

        remove_call_out("doing");
        tell_room(this_object() ,arg);
        line = line + 1;

        if ( (line/time)*time == line )
        {       tell_room(this_object(),HIW"\n\n           ******** ��沥����ͣ�������н����� ********\n\n"NOR);
                user = all_inventory(this_object());
                j=0;
                for(i=0; i<sizeof(user); i++)
                        if ( userp( user[i] )) j++;
                if (j < num)
                {
                        tell_room(me,HIG"�����˸����е�������̫�٣�����ȡ�����������š�\n"NOR);
                        tell_room(me,HIW"\n\n           ******** ������ֹ���������岥 ********\n\n"NOR);
                        call_out("doing",1);
                        return;
                }

                if ( !sizeof( get_dir("/data/movie/answer/") ) )
                {
                        tell_room(me,HIG"������˵�����󱸾������Ͽ���û�����ϣ��޷����о���������ȡ�����������š�\n"NOR);
                        tell_room(me,HIW"\n\n           ******** ������ֹ���������岥 ********\n\n"NOR);
                        call_out("doing",1);
                        return;
                }

                tell_room(me,HIY"�����˸���˵�����н��������ڿ�ʼ���Ȼ���������Ŀ�󣬴�Ҿ�����answer <��> ������\n"NOR);
                tell_room(me,HIY"�����˸���˵������һ��������ȷ����ҿ��Եõ�������Ʊһ�ţ��������׼����Ҫ��ʼ�����ˣ�\n\n"NOR);
                msg = "/data/movie/answer/"+get_dir("/data/movie/answer/")[random(sizeof(get_dir("/data/movie/answer/")))];

                if (!objectp(q_ob = find_object(msg) ))
                        q_ob = load_object(msg);

                question = q_ob->query_question();
                title = q_ob->query_main();
                remove_call_out("start_answer");
                call_out("start_answer",2);

                return;
        }


        call_out("doing",1);
}

void start_answer()
{
        object gold;
        object me = this_object();

        if (!mapp(question))
        {
                tell_room(me,HIG"������˵�������ھ������ϳ��������޷����У������ղŵĲ��š�\n"NOR);

                tell_room(me,HIW"           ******** ������ֹ���������岥 ********\n\n"NOR);
                        call_out("doing",1);
                return;
        }
       set("answered",0);

        if (stringp(question["long"]))
        {
                tell_room(me,HIG"�����˸�������������н�������һ��"+title+"����Ŀ����������ˣ�\n\n"NOR);
                tell_room(me,HIW"              "+question["long"]+"\n\n"NOR);
                tell_room(me,YEL"               ���ڿ�ʼ���� ****������ָ�answer <��>��\n\n"NOR);
                set("answered",0);
                setall();
                move_all();
                call_out("end_answer",60);
        }
}

int do_answer(string arg)
{
        object me = this_player();
        object ob = this_object();
        object caipiao;
        string msg;


        if ( !arg )
        {       write("��Ĵ���ʲô��\n");
                return 1;
        }

        message_vision(CYN"$N�����������"+ arg+"\n"NOR,me);

        if (arg == question["answer"] )
        {       tell_room(ob,HIG"�����˴���������"+me->query("name")+"����ˣ����ξ����ʤ�������㣡\n\n"NOR);
                write_file("/data/movie/caipiao/answerban",question["long"]+"*");

                message_vision(HIG"\n�����˶���$NЦ������ϲ��ʤ�����ֵ��н����𣬽�Ʒ�����ݲ�Ʊ�з��еĸ�����Ʊһ�ţ�ף����ˣ�\n"NOR,me);
                message_vision(HIG"������Ц�ŵݸ�$Nһ�Ÿ�����Ʊ��\n\n"NOR,me);
                caipiao = new(CAIPIAO);
                caipiao->set("number",query_num());
                msg = tostring(query_num()+1);
                CPSYS->set_num(msg);
                caipiao->move(me);
            log_file("test/caipiao", me->query("id")+"��"+caipiao->query("number")+")\n");

                tell_room(ob, HIG "���н����𡿣�"+ me->query("name") + " �ڱ�������ӰԺ�н�������ʤ������ø�����Ʊһ�š�\n" NOR );

                deleteall();
                move_all();
                set("answered",1);
                tell_room(me,HIW"           ******** ���־�����ֹ�����֮��������־��� ********\n\n"NOR);
                remove_call_out("end_answer");
                call_out("doing",1);
        }
        else
             write("�����˶���ҡ��ҡͷ��˵�������ԣ����ԣ�\n");
        return 1;
}

void end_answer()
{
        if ( query("answered"))
                return;

        tell_room(this_object(),HIG"������ʧ����˵������Ȼû��һ�������������������ǿ�ϧ�ˡ��´���Ŭ���ɣ�\n\n"NOR);
        tell_room(this_object(),HIW"           ******** ���־�����ֹ�����֮��������־��� ********\n\n"NOR);
        remove_call_out("end_answer");
        deleteall();
        move_all();
        call_out("doing",1);
}

int do_stop(string arg)
{
        object me = this_player();

        if ( !wizardp(me) )
                return notify_fail("ֻ����ʦ����ֹͣ��������ӳ����Ƭ�ӡ�\n");

        if (!query("play_now"))
                return notify_fail("����û�о��л��\n");

        shout( HIG "���н����𡿣� ������н�������������л��ҵĲ��룬�Ժ������⿪���Ĺ��档\n" NOR );
        write( HIG "���н����𡿣� ������н�������������л��ҵĲ��룬�Ժ������⿪���Ĺ��档\n" NOR );
	remove_call_out("doing");
	remove_call_out("end_answer");
        deleteall();
        move_all();

        delete("play_now");
        in_movie = ({""});

        return 1;
}
