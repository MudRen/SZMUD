//MODIFY BY SCATTER
//LOGIND.C
//V. 1.0
//MODIFY BY APRIL FOR GIFT
//ENRICH SECURITY
//MODIFY BY BUWU FOR OWN STYLE

#include <ansi.h>
#include <command.h>
#include <login.h>

#define NEWS_OB "/cmds/usr/news.c"
//#define SUICIDE_LIST "/log/static/SUICIDE.c"
#define MAX_USERS 225
#define VOTE "/cmds/std/vote.c"

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
        "��", "��", "��", "��", "��", "��", "��",
});
private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
private void init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_login(object me);
object find_body(string name);
int check_legal_id(string arg,object ob);
string check_legal_name(string arg,object ob);
void get_gift(string yn, object ob, mapping my, int select);
string display_attr(int gift);


int isPlayer( object obj )
{
    if ( userp( obj ) ) return 1;
    if ( interactive( obj ) ) return 1;
    if ( environment( obj ) && obj->query( "scheming" ) ) return 1;
    return 0;
}

private void write_ob(object ob,string msg)
{
        if( objectp(ob) && ob->query("language") == "BIG5")
                msg = "/adm/daemons/languaged"->toBig5(msg);

        write(msg);
}

// this function modified by april
//private void random_gift(mapping my)
void random_gift(mapping my, int select)
{
        int i = 10,j;
        int tmpstr, tmpint, tmpcon, tmpdex, tmpend;
        tmpstr = tmpint = tmpcon = tmpdex = tmpend = 10;

/*
        for (i = 0; i < 50; i++) {
                switch (random(5)) {
                case 0: tmpstr++; break;
                case 1: tmpint++; break;
                case 2: tmpcon++; break;
                case 3: tmpdex++; break;
                case 4: tmpend++; break;
                }
        }
*/
	switch (select) {
		case 1: tmpstr = i = my["str"]; break;
		case 2: tmpint = i = my["int"]; break;
		case 3: tmpcon = i = my["con"]; break;
		case 4: tmpdex = i = my["dex"]; break;
		case 5: tmpend = i = my["end"];
	}
	i = 60 - i;
	while (i--) {
		j = random(5);
		if (j == select - 1) {
			i++;
			continue;
		}
		switch (j) {
			case 0: tmpstr++; break;
			case 1: tmpint++; break;
			case 2: tmpcon++; break;
			case 3: tmpdex++; break;
            case 4: tmpend++; break;
		}
	}

        if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
        if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
        if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
        if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;

        my["end"] = 100 - my["dex"] - my["str"] - my["int"] - my["con"];

        // next 3 are randomly selected
        my["kar"] = 10 + random(21);
        my["pat"] = 10 + random(21);
        my["per"] = 60 - my["kar"] - my["pat"];
}

void create()
{
        seteuid(getuid());
        set("channel_id", "���߾���");
}

private void confirm_big5(string arg, object ob)
{
        object *usr;
        int i, wiz_cnt, ppl_cnt, login_cnt;
        object ppl;
        string msg;


        arg = lower_case(arg);

        if( arg == "y" || arg == "yes")
        {
                ob->set("language","BIG5");
                write_ob(ob,"Ok, use BIG5 code.\n\n");
        }
        else
        {
                ob->set("language","GB");
                write_ob(ob,"Ok, use GB code.\n\n");
        }
	cat("adm/etc/welcome2");
        MUDLIST_CMD->main(this_object(), "");
	usr = filter_array( children( USER_OB ), (: isPlayer : ) );
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
        for(i=0; i<sizeof(usr); i++) {
                if( !environment(usr[i]) && !usr[i]->query("scheming") ) login_cnt++;
                else if( wizardp(usr[i]) ) wiz_cnt++;
                else ppl_cnt++;
        }

        msg = "Ŀǰ��վ��������λ���ɡ�" + (string)chinese_number(ppl_cnt);
        msg += "λ��������ϡ��Լ�" + (string)chinese_number(login_cnt) + "λʹ���߳��������С�\n";
        msg += "����Ӣ�����֣�����ҿ�ѡһϲ�������֣���";

        write_ob(ob,msg);

        input_to( (: get_id :), ob );
}

void logon(object ob)
{
        object *usr;
        int i, wiz_cnt, ppl_cnt, login_cnt, iplimit;
    int user_num;
    iplimit = 0;

//    usr = users() + filter(children(LOGIN_OB), (: interactive :));
    usr = filter_array( children( USER_OB ), (: isPlayer : ) );

        cat(WELCOME);
        //UPTIME_CMD->main();


        for(i = 0; i < sizeof(usr); i++)
        {
                if (query_ip_number(usr[i]) == query_ip_number(ob))
                {
                iplimit = iplimit+1;
                }

                if (base_name(usr[i]) == LOGIN_OB)
                        login_cnt++;
                else if (wizardp(usr[i]))
                {
                        if (! usr[i]->query("env/invisible")) wiz_cnt++;
                }
                else ppl_cnt++;
        }



        if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
                write_ob(ob,"��ĵ�ַ�ڱ� MUD ���ܻ�ӭ��Your IP not welcome in this MUD.\n");
                destruct(ob);
                return;
        }

//#ifdef MAX_USERS
//      if( sizeof(users()) >= MAX_USERS - 4 ) {
//                      write_ob(ob,"�Բ���" + MUD_NAME + "��ʹ�����Ѿ�̫���ˣ������������\n");
//                      destruct(ob);
//                      return;
//    }

//#endif
/*
    write_ob(ob,HIG"--------------------- V. 2.1 -----------------------------\n"NOR);
    write_ob(ob,HIG"  FOLLOWING DATA ARE USED BY SCATTER FOR DEBUG PURPOSE    \n"NOR);
    write_ob(ob,HIG"----------------------------------------------------------\n"NOR);
    write_ob(ob,HIG"     TEST DATA           INFORMATION                      \n"NOR);
    write_ob(ob,HIG"----------------------------------------------------------\n"NOR);
    write_ob(ob,HIW" 1)MULTI-ACCESS CONTROL  CURRENTLY THERE ARE " + iplimit + " SAME IP\n"NOR);
    write_ob(ob,HIG"----------------------------------------------------------\n"NOR);
    write_ob(ob,HIW" 2)ONLINE COUNT          CURRENTLY THERE ARE " + sizeof(usr) + " USER ONLINE\n"NOR);
    write_ob(ob,HIG"----------------------------------------------------------\n"NOR);

*/
        if (iplimit > 20)
        {
                write_ob(ob,"�Բ������� IP �Ѿ���̫��������ߣ���ص����õĴ������ԡ�\n");
                destruct(ob);
                return;
        }

        write_ob(ob,"\nAre you using BIG5 font(Y/N)?\n");
        input_to("confirm_big5", ob);
}

private void get_id(string arg, object ob)
{
        object ppl;
        string language, check_passwd, timer;
	int a, b, c, d, t;
        arg = lower_case(arg);
        if( !check_legal_id(arg,ob)) {
                write_ob(ob,"����Ӣ�����֣�");
                input_to("get_id", ob);
                return;
        }

#ifdef MAX_USERS
        if( (string)SECURITY_D->get_status(arg)=="(player)"
        && sizeof(users()) >= MAX_USERS - 4) {
                ppl = find_body(arg);
                // Only allow reconnect an interactive player when MAX_USERS exceeded.
                if( !ppl || !interactive(ppl) ) {
                        write_ob(ob,"�Բ���" + MUD_NAME + "��ʹ�����Ѿ�̫���ˣ������������\n");
                        destruct(ob);
                        return;
                }
        }
#endif


        if( wiz_level(arg) && !SECURITY_D->valid_wiz_login(arg, query_ip_number(ob)) ) {
                write_ob(ob,"�Բ�����ӵǼǵĵ�ַʹ����ʦ�ʺš�\n");
                log_file("WIZ_LOGIN", sprintf("%s: Attempting login %s from %s\n", ctime(time()), arg, query_ip_name(ob)));
                destruct(ob);
                return;
        }


        /*write_ob(ob,"\n�����ݡ����ڵĵ�ַ�ǣ�sun.stanford.edu 5555 �� 171.64.200.85 5555\n\n\n");
        if (wiz_level(arg) == 0) {
                destruct(ob);
                return;
        }*/

        if( wiz_level(arg) < wiz_lock_level ) {
                write_ob(ob,"�Բ���" + MUD_NAME + "Ŀǰ�ѱ�������ֻ��һ���ȼ�������"
                        + "�������߽��롣\n");
                destruct(ob);
                return;
        }

        if( (string)ob->set("id", arg) != arg ) {
                write_ob(ob,"Failed setting user name.\n");
                destruct(ob);
                return;
        }

//      if( arg=="guest" ) {
//              // If guest, let them create the character.
//              confirm_id("Yes", ob);
//              return;
//      } else


        if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
                language = ob->query("language");
                if( ob->restore() ) {
			if( (time()-(int)ob->query("last_on"))/86400 < 3 && ob->query("pw-gs") == "yes"){
				timer = "";
				t = time()-(int)ob->query("last_on");
				a = 2 - (t / 86400);
				b = 23 - ((t % 86400) / 3600);
				c = 59 - ((t % 3600) / 60);
				d = 59 - (t % 60);
				if (a != 0) timer = timer + chinese_number(a)+"��";
				if (b != 0) timer = timer + chinese_number(b)+"Сʱ";
				if (c != 0) timer = timer + chinese_number(c)+"����";
				if (d != 0) timer = timer + chinese_number(d)+"��";
	                        write_ob(ob,HIR"\n���������Ѿ���ʧ������"+timer+"���������ʹ�����룡\n"NOR);			
		                destruct(ob);
		                return;
		        }//add report the loss of password by lisser.
			if( !ob->query("check_password") ){
	                        ob->set("language",language);
	                        write_ob(ob,"��û�����ñ������룬�����������á�\n");
				write_ob(ob,HIR"******************************************************************\n"NOR);
				write_ob(ob,HIR"*                                                                *\n"NOR);
				write_ob(ob,HIR"*                       "NOR+NOR"������"HIW"��������"HIR"                           *\n"NOR);
				write_ob(ob,HIR"*                                                                *\n"NOR);
				write_ob(ob,HIR"*����"HIW"��������"NOR"������������չ�����"HIY"Ψһƾ֤"NOR"���ճ�������Ϸʱ��������"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"����"HIY"ʹ������"NOR"����"HIY"ʹ������"NOR"����ĳ��ԭ����������Ϳ������뱣������"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"ȡ�������������������������ط����룬��ʵ������Ҳ"HIY"�����ٹ�"NOR"����"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"�ˡ���˱�������ı��ܷǳ���Ҫ��"HIY"��ȷ��û�еڶ�����֪�������һ���"HIR"*\n"NOR);
				write_ob(ob,HIR"*"HIY"Ҫ���ڹؼ�ʱ�����������"NOR"�������ó�������ʮλ�ı������롣        "HIR"*\n"NOR);	
				write_ob(ob,HIR"******************************************************************\n"NOR);
			        write_ob(ob,"���趨���ı������룺");
	                        input_to("setcheck_password", 1, ob);
	                        return;
	                }
	                if( (time()-(int)ob->query("last_on"))/86400 >= 3 && ob->query("pw-gs") == "yes"){
				write_ob(ob,HIG"��������ı��������ʹ������������ã�"NOR);
				input_to("reset_passwd", 1, ob);		
				return;
			}
                        ob->set("language",language);
                        write_ob(ob,"������ʹ������(���ʹ����������������"HIR"Y"NOR"����"HIR"y"NOR")��");
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write_ob(ob,"�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
                destruct(ob);
                return;
        } else { // check if someone is already trying to create this id
                if( find_login(ob) ) {
                        write_ob(ob,"����Ҳ�ڴ�����������ѡ������Ӣ�����֡�\n");
                        write_ob(ob,"����Ӣ�����֣�");
                        input_to("get_id", ob);
                        return;
                }
        }

// dts: check reg-ban setting
        if (REGBAN_D->is_banned(query_ip_name(ob)) == 1) {
                write_ob(ob,"�� MUD ����ӭ�㴴���µ����");
                destruct(ob);
                return;
        }

        write_ob(ob,"ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
        input_to("confirm_id", ob);
}

private void setcheck_password(string pass, object ob)
{
        write_ob(ob,"\n");
        if( strlen(pass)<10 ) {
                write_ob(ob,"��������ĳ�������Ҫʮ����Ԫ�����������ı������룺");
                input_to("setcheck_password", 1, ob);
                return;
        }
        ob->set("check_password", crypt(pass,0) );
        write_ob(ob,"��������һ�����ı������룬��ȷ����û�Ǵ�");
        input_to("confirm_setcheck_password", 1, ob);
}
private void confirm_setcheck_password(string pass, object ob)
{
        mapping my;
        string old_pass;
        write_ob(ob,"\n");
        old_pass = ob->query("check_password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write_ob(ob,"����������ı������벢��һ�����������趨һ�α������룺");
                input_to("setcheck_password", 1, ob);
                return;
       }
        write_ob(ob,"������ʹ�����룺");
        input_to("get_passwd", 1, ob);       
}

private void reset_passwd(string checkpass, object ob)
{
	string my_checkpass, newpass;
	object user;
	write_ob(ob,"\n");
	my_checkpass = ob->query("check_password");
	if(crypt(checkpass, my_checkpass) != my_checkpass)
	{
		write_ob(ob,HIR"�Բ�����ı������벻�ԣ�\n"NOR);
		destruct(ob);
		return;
	}
        write_ob(ob,"���趨������ʹ�����룺");
        input_to("setnew_password", 1, ob);
}

private void setnew_password(string pass, object ob)
{
        write_ob(ob,"\n");
        if( strlen(pass)<5 ) {
                write_ob(ob,"ʹ������ĳ�������Ҫ�����Ԫ������������ʹ�����룺");
                input_to("setnew_password", 1, ob);
                return;
        }
        ob->set("password", crypt(pass,0) );
        write_ob(ob,"��������һ������ʹ�����룬��ȷ����û�Ǵ�");
        input_to("get_passwd", 1, ob);
}

private void get_passwd(string pass, object ob)
{
        string my_pass, file, *tmp, old_pass;
        object user;
        int cnt;

        write_ob(ob,"\n");
	if (ob->query("pw-gs") == "yes")
	{
	        write_ob(ob,"\n");
	        old_pass = ob->query("password");
	        if( crypt(pass, old_pass)!=old_pass ) {
	                write_ob(ob,"�����������ʹ�����벢��һ�����������趨һ��ʹ�����룺");
	                input_to("setnew_password", 1, ob);
	                return;
		}
		ob->set("pw-gs","no");
                log_file("passwd-gs", sprintf("[%s]  %s(%s)�� [%s] ������������á�\n", ctime(time()), ob->query("name"), ob->query("id"), query_ip_name(ob)));
        }else{		
	        my_pass = ob->query("password");
		if(pass == "Y" || pass == "y")
		{
			
	                if( wizardp(ob->query("id")) )
	                {
				write_ob(ob,HIR"��֪�����ɵı������룿�����һ��ᵱ�����ʰɡ�"NOR);
		                destruct(ob);
		                return;
	               	}
		        if(ob->query("pw-gs") != "yes"){
				write_ob(ob,HIC"��������ı���������������ʧ��"NOR);
				input_to("gs_passwd", 1, ob);		
				return;
			}
		}
	        if( crypt(pass, my_pass) != my_pass ) {
	                write_ob(ob,"ʹ���������\n");
	                if( wiz_level(ob->query("id")) )
	                        log_file("WIZ_LOGIN", sprintf("%s: Failed login %s from %s\n",
	                                ctime(time()), ob->query("id"), query_ip_name(ob)));
	                destruct(ob);
	                return;
	        }
	}
/*        // Check if this player has already suicided before.
        file = read_file(SUICIDE_LIST);
        if ( sizeof(file) > 0 ) {
           tmp = explode(file, "\n");

           for( cnt=0; cnt < sizeof(tmp); cnt++ ) {
                if( tmp[cnt][0] == '#' || tmp[cnt][0] == '\n' || tmp[cnt] == "" )
                        continue;
                else if ( strsrch( tmp[cnt], "*"+ob->query("id")+" commits" ) >= 0 ) {
                        write_ob(ob,"���Ѿ���ɱ�ˣ���ô�ܹ������أ�\n");
                        destruct(ob);
                        return;
                }
            }
        }
*/
        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (user) {
                 user->set("language",ob->query("language"));
                if( user->query_temp("netdead") ) {
                        reconnect(ob, user);
                        return;
                }
                write_ob(ob,"��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( objectp(user = make_body(ob)) ) {
                if( user->restore() ) {
                   user->set("language",ob->query("language"));
                        log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n", user->query("name"), user->query("id"),
                                query_ip_name(ob), ctime(time()) ) );
                        enter_world(ob, user);
                        return;
                } else {
                        destruct(user);
                }
        }
        write_ob(ob,"�������´���������\n");
        confirm_id("y", ob);
}

private void gs_passwd(string checkpass, object ob)
{
	string my_checkpass, newpass;
	object user;
	write_ob(ob,"\n");
	my_checkpass = ob->query("check_password");
	if(crypt(checkpass, my_checkpass) != my_checkpass)
	{
		write_ob(ob,HIR"�Բ�����ı������벻�ԣ�\n"NOR);
		destruct(ob);
		return;
	}
	ob->set("pw-gs","yes");
	ob->set("last_on",time());
        log_file("passwd-gs", sprintf("[%s]  %s(%s)�� [%s] ��������й�ʧ��\n", ctime(time()), ob->query("name"), ob->query("id"), query_ip_name(ob)));
	ob->save();
	write_ob(ob,HIG"���������������趨����ʹ�����룡\n"NOR);
	destruct(ob);
	return;
}

private void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if( yn=="" ) {
                write_ob(ob,"��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write_ob(ob,"�ðɣ���ӭ�´�������\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
                        + " )����ȡ���������Ƶ����\n");
                log_file( "USAGE", sprintf("%s(%s) replaced by %s (%s)\n", user->query("name"), user->query("id"),
                        query_ip_name(ob), ctime(time()) ) );
        }

        // Kick out tho old player.
        old_link = user->query_temp("link_ob");
        if( old_link ) {
                exec(old_link, user);
                destruct(old_link);
        }

        reconnect(ob, user);
}

private void confirm_id(string yn, object ob)
{
        if( yn=="" ) {
                write_ob(ob,"ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
                input_to("confirm_id", ob);
                return;
        }

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write_ob(ob,"�ðɣ���ô��������������Ӣ�����֣�");
                input_to("get_id", ob);
                return;
        }
        write_ob(ob, @TEXT

���������ĸ��մ���������������ִ��������������Ժ��ܸ��ģ�
����������������Ź۵���������ɾ���������벻Ҫѡ���ӹС˵��
��������������

TEXT
        );
        write_ob(ob,"�����������֣�");
        input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
        if( !(arg = check_legal_name(arg,ob) )) {
                write_ob(ob,"�����������֣�");
                input_to("get_name", ob);
                return;
        }
        //write_ob(ob,"%O\n", ob);
        if( objectp(ob) && ob->query("language") == "BIG5")
                arg = "/adm/daemons/languaged"->toGB(arg);
        ob->set("name", arg);

        write_ob(ob,"���趨����ʹ�����룺");
        input_to("new_password", 1, ob);
}
private void new_password(string pass, object ob)
{
        write_ob(ob,"\n");
        if( strlen(pass)<5 ) {
                write_ob(ob,"ʹ������ĳ�������Ҫ�����Ԫ������������ʹ�����룺");
                input_to("new_password", 1, ob);
                return;
        }
        ob->set("password", crypt(pass,0) );
        write_ob(ob,"��������һ������ʹ�����룬��ȷ����û�Ǵ�");
        input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
        mapping my;
        string old_pass;
        write_ob(ob,"\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write_ob(ob,"�����������ʹ�����벢��һ�����������趨һ��ʹ�����룺");
                input_to("new_password", 1, ob);
                return;
        }
				write_ob(ob,HIR"******************************************************************\n"NOR);
				write_ob(ob,HIR"*                                                                *\n"NOR);
				write_ob(ob,HIR"*                       "NOR+NOR"������"HIW"��������"HIR"                           *\n"NOR);
				write_ob(ob,HIR"*                                                                *\n"NOR);
				write_ob(ob,HIR"*����"HIW"��������"NOR"������������չ�����"HIY"Ψһƾ֤"NOR"���ճ�������Ϸʱ��������"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"����"HIY"ʹ������"NOR"����"HIY"ʹ������"NOR"����ĳ��ԭ����������Ϳ������뱣������"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"ȡ�������������������������ط����룬��ʵ������Ҳ"HIY"�����ٹ�"NOR"����"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"�ˡ���˱�������ı��ܷǳ���Ҫ��"HIY"��ȷ��û�еڶ�����֪�������һ���"HIR"*\n"NOR);
				write_ob(ob,HIR"*"HIY"Ҫ���ڹؼ�ʱ�����������"NOR"�������ó�������ʮλ�ı������롣        "HIR"*\n"NOR);	
				write_ob(ob,HIR"******************************************************************\n"NOR);
        write_ob(ob,"���趨���ı������룺");
        input_to("check_password", 1, ob);
}

private void check_password(string pass, object ob)
{
        write_ob(ob,"\n");
        if( strlen(pass)<10 ) {
                write_ob(ob,"��������ĳ�������Ҫʮ����Ԫ�����������ı������룺");
                input_to("check_password", 1, ob);
                return;
        }
        ob->set("check_password", crypt(pass,0) );
        write_ob(ob,"��������һ�����ı������룬��ȷ����û�Ǵ�");
        input_to("confirm_check_password", 1, ob);
}

private void confirm_check_password(string pass, object ob)
{
        mapping my;
        string old_pass;
        write_ob(ob,"\n");
        old_pass = ob->query("check_password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write_ob(ob,"����������ı������벢��һ�����������趨һ�α������룺");
                input_to("check_password", 1, ob);
                return;
        }
        write_ob(ob,"
һ������������츳����������Ϸ����ҵ�ְҵ���书�������ݡ��ֽ׶�������������Ҫ�츳��

        "HIG"����"NOR"��"HIC"Ӱ�칥����������������ĳЩ�书��ְҵ������Ҳ��Ҫ��"NOR"
        "HIG"����"NOR"��"HIC"Ӱ��ѧϰ�书�ؼ��������书���ٶȼ����ʦ����������"NOR"      
        "HIG"����"NOR"��"HIC"Ӱ�������������ӵ��������Լ�����ľ����������ֵ��"NOR"
        "HIG"��"NOR"��"HIC"Ӱ���������ܵ�������ĳЩְҵ��Ҫ�ܸߵ�����"NOR"
        "HIG"ʣ��"NOR"��"HIC"����Ϸû���κ�Ӱ�죬ʣ��ֵԽ�ͣ���ҵ������츳��Խ�ߡ�"NOR"

�������Լ�ָ������һ���ֵ���������� 0 ����ϵͳ���������
����������ѡ��(0-4)��
");

// april add
	input_to("select_gift", ob);
// april end

/* by april
        my = ([]);
        random_gift(my);
        write_ob(ob,sprintf("\n����[%d]�� ����[%d]�� ����[%d]�� ��[%d]�� ʣ��[%d]\n",
                                         my["str"], my["int"], my["con"], my["dex"], my["end"]) );

  write_ob(ob,"��������һ���츳��");
  input_to("get_gift", ob, my);
*/
}

// april add
void select_gift(string yn, object ob)
{
        int i;
        mapping my = ([]);

        if (!sscanf(yn, "%d", i) || i < 0 || i > 4) {
                write("\n�������������ѡ��");
                input_to("select_gift", ob);
                return;
        }
        if (i) {
                write("\n����������Ҫ����ֵ(10-30)��");
                input_to("set_gift", ob, my, i);
        } else get_gift(" ", ob, my, i);
}

void set_gift(string yn, object ob, mapping my, int select)
{
        int i;

        if (!sscanf(yn, "%d", i) || i < 10 || i > 30) {
                write("\n��ֵ�������������룺");
                input_to("set_gift", ob, my, select);
                return;
        }
        switch (select) {
                case 1: my["str"] = i; break;
                case 2: my["int"] = i; break;
                case 3: my["con"] = i; break;
                case 4: my["dex"] = i;
        }
        get_gift(" ", ob, my, select);
}
// april end

// this function modified by april
// private void get_gift(string yn, object ob, mapping my)
void get_gift(string yn, object ob, mapping my, int select)
{
        if (yn[0] != 'y' && yn[0] != 'Y') {
//                random_gift(my);
                random_gift(my, select);
/*                write_ob(ob,sprintf("\n����[%d]�� ����[%d]�� ����[%d]�� ��[%d]�� ʣ��[%d]\n",
                                         my["str"], my["int"], my["con"], my["dex"], my["end"]) );

                write_ob(ob,"��ͬ����һ���츳��");
                input_to("get_gift", ob, my);
*/

			printf("\n����[%s]������[%s]������[%s]����[%s]�� ʣ��[%s]\n",
			display_attr(my["str"]),
			display_attr(my["int"]),
			display_attr(my["con"]),
			display_attr(my["dex"]),
			display_attr(my["end"]));
			
			write("��ͬ����һ���츳��");
			input_to("get_gift", ob, my, select);

        }
        if (yn[0] == 'y' || yn[0] == 'Y') {
                                write_ob(ob,"���ĵ����ʼ���ַ��");
                        input_to("get_email", ob, my);
        }
}

string display_attr(int gift)
{
	if (gift > 24) return HIY + gift + NOR;
	if (gift < 16) return CYN + gift + NOR;
	return "" + gift;
}

private void get_email(string email, object ob, mapping my)
{
        object user;
        write_ob(ob,"\n");
        if (email == "" || strsrch(email, "@") == -1 || strsrch(email, ".")==-1){
                write_ob(ob,"�����ʼ���ַ��Ҫ�� id@address �ĸ�ʽ��\n");
                write_ob(ob,"���ĵ����ʼ���ַ(���ǽ�������֪ͨ��������Ϣ������ IP ���)��");
                input_to("get_email", ob, my);
                return;
        }

        ob->set("email", email);
        ob->set("registered", "yes");

        // If you want do race stuff, ask player to choose one here, then you can
        // set the user's body after the question is answered. The following are
        // options for player's body, so we clone a body here.
        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
                return;
        user->set("str", my["str"]);
        user->set("dex", my["dex"]);
        user->set("con", my["con"]);
        user->set("int", my["int"]);
        ob->set("registered", "yes");
        user->set("registered", "no");
        user->set("newbie", "yes");
        write_ob(ob,"��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
        input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
        write_ob(ob,"\n");
        if( gender=="" ) {
                write_ob(ob,"��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "����");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "Ů��" );
        else {
                write_ob(ob,"�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }

        log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
                query_ip_name(ob), ctime(time()) ) );
        init_new_player(user);
        enter_world(ob, user);
        write_ob(ob,"\n");
}

object make_body(object ob)
{
        string err;
        object user;
        int n;

        user = new(ob->query("body"));
        if(!user) {
                write_ob(ob,"���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
                write_ob(ob,err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set("language", ob->query("language"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}

private void init_new_player(object user)
{
        object money;

        user->set("title", "��ͨ����");
        user->set("birthday", time() );
        user->set("potential", 99);
        user->set("newbie", "yes");

        user->set("env/prompt", "None");
        user->set("channels", ({ "chat", "rumor", "jiaoyi", "menpai" }) );
   	user->create_human_body();

//      money=new("/clone/money/silver");
//      money->set_amount(10);
//      money->move(user);

        // In case of new player, we save them here right aftre setup
//      user->move("/adm/register/reg_room");
//      user->set("startroom", "/adm/register/reg_room");
//      user->save();
        // compeleted.
}


varargs void enter_world(object ob, object user, int silent)
{
        object cloth, room;
        mapping skill_status, my;
        string startroom, family, clas;
        string *sname;
        int select, i, level;
        float exper;

        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        user->set("registered", ob->query("registered"));
        exec(user, ob);

        user->set("language", ob->query("language"));
        write_ob(user,"\nĿǰȨ�ޣ�" + wizhood(user) + "\n");

        user->setup();

        ob->save();

        if( MARRY_D->validate_marriage(user) )
                new("/d/city/obj/pring")->move(user);

        // general user data login check, like combat_exp, balance, clothing.
        UPDATE_D->login_check(user);
/*
        if( user->query("mud_age") > 10000000 )
    	{
    	    user->add("mud_age",-915148800);
    	    if ( (int) user->query( "max_qi" ) > 0 )
    	        user->set( "qi", (int) user->query( "max_qi" ) );
    	    else
    	    {
    	        user->set( "max_qi", 1000 );
    	        user->set( "qi", 1000 );
    	    }
    	    
    	    if ( (int) user->query( "max_jing" ) > 0 )
    	        user->set( "jing", (int) user->query( "max_jing" ) );    	  
    	    else
    	    {
    	        user->set( "max_jing", 1000 );
    	        user->set( "eff_jing", 1000 );
    	        user->set( "jing", 1000 );
    	    }
    	    
    	    user->set("potential",500);
    	    set_temp("quit/forced", 1);
            command("quit");
            return;
        }
        else if ( user->query("mud_age") < 0 )
        {
            user->set( "mud_age", 1000 );
    	    if ( (int) user->query( "max_qi" ) > 0 )
    	        user->set( "qi", (int) user->query( "max_qi" ) );
    	    else
    	    {
    	        user->set( "max_qi", 1000 );
    	        user->set( "qi", 1000 );
    	    }
    	    
    	    if ( (int) user->query( "max_jing" ) > 0 )
    	        user->set( "jing", (int) user->query( "max_jing" ) );    	  
    	    else
    	    {
    	        user->set( "max_jing", 1000 );
    	        user->set( "eff_jing", 1000 );
    	        user->set( "jing", 1000 );
    	    }
    	    user->set("potential",500);
    	}
*/
             
        // Menpai specific user data check
        // should have been moved into UPDATE_D if random_gift() were not used.
        if ( user->query("yijin_wan") && user->query("yijin_wan") < user->query("age") - 14 )
        {
                //user->add("max_neili",  -10);
                //user->add("eff_jingli", -10);
                //if (user->query("eff_jingli") < 0) user->set("eff_jingli",0);
                //if (user->query("max_neili") < 0) user->set("max_neili",0);

                my = ([]);
                random_gift(my,0);
                user->set("str", my["str"] - random(user->query("yijin_wan") - user->query("age") + 14));
                user->set("dex", my["dex"] - random(user->query("yijin_wan") - user->query("age") + 14));
                user->set("con", my["con"] - random(user->query("yijin_wan") - user->query("age") + 14));
                user->set("int", my["int"] - random(user->query("yijin_wan") - user->query("age") + 14));
                //user->set("yijin_wan", user->query("age") - 13);

                tell_object(user, HIR "��һ����δ����̥�׽��裬�������𣡣���\n"NOR);
        }

        user->save();

        if( !silent ) {
                if (ob->query("registered") == 0)
                {
                        //cat(UNREG_MOTD);
write("������������������������������������������������������������������������
��      ע�⣡����

                  ����û��ע�ᣬһ���ݵ����ֻ����ע������ʹ�á�

                  ע��Ĳ���ܼ򵥣�����Ҫ���κδ���ʦ�����һ�����
                  �ʼ����ţͣ��ɣ̣������򼸷��ӣ�����һ�죬�����ˡ�
������������������������������������������������������������������������\n");
                }
                else
{
                        //cat(MOTD);
                        write(
"����������������������������������������������������������������������������
��      ���� help rules ����ѯ��Ϸ������Ϊ���汻ɾ�����ʺţ�һ���Ǿ���
        ��ȡ�������ܱ��ָ��������Ĵη������ң������ݡ�����ȡ���ùرյ�¼��
        ַ���ط���
��      �������� help��help intro��help newbie�� help commands ����
        ������ѯ��Ϸ������Ҳ���Բ�ѯ�����ݡ���ҳ�ϵ����˵����
��      ��ס��ʱ�浵�����ڵ�����ɵ���Ϸ������ʧ�������ݡ��Ų�����
��      ����ɱ�����в��õ��ʺš�һ�������ϲ��õķ����˺���ʱ���ܱ������
��      ���֮���ͨ���������������ɲ����ڡ����ݡ��ı�����Χ��
����������������������������������������������������������������������������\n");

}
                write(sprintf( HIR"�ϴ����ߵ�ַ��\t%s( %s )\n\n"NOR,
                        ob->query("last_from"),
                        ctime(ob->query("last_on") )
                ) );

                write(
HIG"
       ********************************************************************
       *                                                                  *
       * �������ϸ�Ķ������� help rules �е����ݣ���������������� sos ��*
       *                                                                  *
       ********************************************************************

"NOR);


        if( strsrch(ctime(time()), "Dec 24") != -1
                || strsrch(ctime(time()), "Dec 25") != -1
                || strsrch(ctime(time()), "Dec 26") != -1
                )
        {
          cat("/adm/etc/welcome_christmas");
        }

        if( strsrch(ctime(time()), "Jan 1") != -1
                || strsrch(ctime(time()), "Dec 30") != -1
                || strsrch(ctime(time()), "Dec 31") != -1
                || strsrch(ctime(time()), "Jan 2") != -1
                || strsrch(ctime(time()), "Jan 3") != -1
        )
        {
          cat("/adm/etc/welcome_newyear");
        }
	//add by yujie,fix by lisser
	        i=sizeof( NEWS_OB->query("notes") ) - user->query("LastReadNews");
	        if ( i>0 ) write(HIW"����"NOR+HIG+chinese_number(i)+NOR+HIW"��������δ�Ķ�������news�������Ķ�����������Ҫ��\n"NOR);
		VOTE->main(user,"list");


                if( user->is_ghost() )
                        startroom = DEATH_ROOM;
                else if( !stringp(startroom = user->query("startroom"))
                        || !user->query("family") && user->query("combat_exp") < 1)
                        startroom = "/d/city/kedian";
/*              if ((user->query("registered") != "yes" && user->query("newbie")||
                        REGI_D->is_banned_email(ob->query("email"))) &&
                        wizhood(user) == "(player)")*/
                if (user->query("newbie")== "yes" && wizhood(user) == "(player)")
		{
			CHANNEL_D->do_channel( this_object(), "rumor",sprintf("��˵%s(%s)��ʼ������ ���� ���������ˡ�", user->name(),user->query("id")));
                        user->move("/d/welcome/welcome");
		}
                else if( user->query("death_count") > 200 && user->query("combat_exp") < 50000 )
                        user->move("/d/death/block.c");
                else if( !catch(load_object(startroom)) )
                        user->move(startroom);
                else {
                        user->move(START_ROOM);
                        startroom = START_ROOM;
                        user->set("startroom", START_ROOM);
                }
                tell_room(startroom, user->query("name") + "���߽���������硣\n",
                        ({user}));
        }
	if( wizhood(user)=="(admin)" || wizhood(user)=="(arch)" || wizhood(user)=="(wizard)") return 0;
        if (!user->query_temp("cursed"))
	if ( !user->query( "blocked" ) )
	     CHANNEL_D->do_channel( this_object(), "sys",
	                 sprintf("%s(%s)��%s���߽��롣", user->name(),user->query("id"), query_ip_name(user)) );
        TOPTEN_D->topten_checkplayer(user);
/*
//add by yujie
        i=sizeof( NEWS_OB->query("notes") ) - user->query("LastReadNews");
        if ( i>0 ) write(HIW"����"NOR+HIG+chinese_number(i)+NOR+HIW"��������δ�Ķ�������news�������Ķ�����������Ҫ��\n"NOR);
*/
}

varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        user->reconnect();
        if( !silent ) {
                tell_room(environment(user), user->query("name") + "�������߻ص�������硣\n",
                ({user}));
        }
	if( wizhood(user)=="(admin)" || wizhood(user)=="(arch)" || wizhood(user)=="(wizard)") return 0;
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)��%s�������߽��롣", user->query("name"),user->query("id"), query_ip_name(user)) );
}

int check_legal_id(string id,object ob)
{
        int i;

        i = strlen(id);

        if( (strlen(id) < 3) || (strlen(id) > 8 )
          && (string)SECURITY_D->get_status(id) == "(player)" ) {
                write_ob(ob,"�Բ������Ӣ�����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
                return 0;
        }
        while(i--)
                if( id[i]<'a' || id[i]>'z' ) {
                        write_ob(ob,"�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
                        return 0;
                }

        return 1;
}

string check_legal_name(string name,object ob)
{
        int i,j;

        i = strlen(name);

        if( (strlen(name) < 2) || (strlen(name) > 8 ) || i % 2) {
                write_ob(ob,"�Բ�������������ֱ����� 1 �� 4 �������֡�\n");
                return 0;
        }
        for (j = 0; j < i; j++) {
//              if( name[i]<=' ' ) {
//                      write_ob(ob,"�Բ�������������ֲ����ÿ�����Ԫ��\n");
//                      return 0;
//              }
                if( j%2==0 && !is_chinese(name[j..j+1]) ) {
                        name[j]+=128; name[j+1]+=128;
//                      write_ob(ob,"�Բ��������á����ġ�ȡ���֡�\n");
//                      return 0;
                }
        }
        if( member_array(name, banned_name)!=-1 ) {
                write_ob(ob,"�Բ����������ֻ���������˵����š�\n");
                return 0;
        }

        return name;
}

object find_login(object me)
{
        object ob, *login;
        string id;

        if( !objectp(me) || !stringp(id = me->query("id")) )
                return 0;
        login = children(LOGIN_OB);
        for(int i=0; i<sizeof(login); i++)
                if( clonep(login[i]) && login[i] != me &&
                    login[i]->query("id") == id )
                        return login[i];

        return 0;
}

object find_body(string name)
{
        object ob, *body;

        if( objectp(ob = find_player(name)) )
                return ob;
        body = children(USER_OB);
        for(int i=0; i<sizeof(body); i++)
                if( clonep(body[i])
                &&      getuid(body[i]) == name ) return body[i];

        return 0;
}

int set_wizlock(int level)
{
        if( wiz_level(this_player(1)) <= level )
                return 0;
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;
        wiz_lock_level = level;
        return 1;
}
