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
        "你", "你", "我", "他", "她", "它", "它",
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
        set("channel_id", "连线精灵");
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

        msg = "目前本站共有若干位神仙、" + (string)chinese_number(ppl_cnt);
        msg += "位玩家在线上、以及" + (string)chinese_number(login_cnt) + "位使用者尝试连线中。\n";
        msg += "您的英文名字（新玩家可选一喜欢的名字）：";

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
                write_ob(ob,"你的地址在本 MUD 不受欢迎。Your IP not welcome in this MUD.\n");
                destruct(ob);
                return;
        }

//#ifdef MAX_USERS
//      if( sizeof(users()) >= MAX_USERS - 4 ) {
//                      write_ob(ob,"对不起，" + MUD_NAME + "的使用者已经太多了，请待会再来。\n");
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
                write_ob(ob,"对不起，您的 IP 已经有太多玩家在线，请关掉不用的窗口再试。\n");
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
                write_ob(ob,"您的英文名字：");
                input_to("get_id", ob);
                return;
        }

#ifdef MAX_USERS
        if( (string)SECURITY_D->get_status(arg)=="(player)"
        && sizeof(users()) >= MAX_USERS - 4) {
                ppl = find_body(arg);
                // Only allow reconnect an interactive player when MAX_USERS exceeded.
                if( !ppl || !interactive(ppl) ) {
                        write_ob(ob,"对不起，" + MUD_NAME + "的使用者已经太多了，请待会再来。\n");
                        destruct(ob);
                        return;
                }
        }
#endif


        if( wiz_level(arg) && !SECURITY_D->valid_wiz_login(arg, query_ip_number(ob)) ) {
                write_ob(ob,"对不起，请从登记的地址使用巫师帐号。\n");
                log_file("WIZ_LOGIN", sprintf("%s: Attempting login %s from %s\n", ctime(time()), arg, query_ip_name(ob)));
                destruct(ob);
                return;
        }


        /*write_ob(ob,"\n【神州】现在的地址是：sun.stanford.edu 5555 或 171.64.200.85 5555\n\n\n");
        if (wiz_level(arg) == 0) {
                destruct(ob);
                return;
        }*/

        if( wiz_level(arg) < wiz_lock_level ) {
                write_ob(ob,"对不起，" + MUD_NAME + "目前已被锁定，只有一定等级的神仙"
                        + "才能连线进入。\n");
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
				if (a != 0) timer = timer + chinese_number(a)+"天";
				if (b != 0) timer = timer + chinese_number(b)+"小时";
				if (c != 0) timer = timer + chinese_number(c)+"分钟";
				if (d != 0) timer = timer + chinese_number(d)+"秒";
	                        write_ob(ob,HIR"\n您的密码已经挂失，请在"+timer+"后重设你的使用密码！\n"NOR);			
		                destruct(ob);
		                return;
		        }//add report the loss of password by lisser.
			if( !ob->query("check_password") ){
	                        ob->set("language",language);
	                        write_ob(ob,"您没有设置保密密码，请您现在设置。\n");
				write_ob(ob,HIR"******************************************************************\n"NOR);
				write_ob(ob,HIR"*                                                                *\n"NOR);
				write_ob(ob,HIR"*                       "NOR+NOR"请输入"HIW"保密密码"HIR"                           *\n"NOR);
				write_ob(ob,HIR"*                                                                *\n"NOR);
				write_ob(ob,HIR"*　　"HIW"保密密码"NOR"是你的人物最终归属的"HIY"唯一凭证"NOR"。日常进行游戏时，你所用"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"的是"HIY"使用密码"NOR"。当"HIY"使用密码"NOR"出于某种原因被遗忘，你就可以输入保密密码"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"取回你的人物。这样不用再找神仙重发密码，事实上神仙也"HIY"不会再管"NOR"这事"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"了。因此保密密码的保密非常重要，"HIY"请确保没有第二个人知道，并且还需"HIR"*\n"NOR);
				write_ob(ob,HIR"*"HIY"要你在关键时候能想得起来"NOR"。请设置长度至少十位的保密密码。        "HIR"*\n"NOR);	
				write_ob(ob,HIR"******************************************************************\n"NOR);
			        write_ob(ob,"请设定您的保密密码：");
	                        input_to("setcheck_password", 1, ob);
	                        return;
	                }
	                if( (time()-(int)ob->query("last_on"))/86400 >= 3 && ob->query("pw-gs") == "yes"){
				write_ob(ob,HIG"请输入你的保密密码对使用密码进行重置："NOR);
				input_to("reset_passwd", 1, ob);		
				return;
			}
                        ob->set("language",language);
                        write_ob(ob,"请输入使用密码(如果使用密码遗忘请输入"HIR"Y"NOR"或者"HIR"y"NOR")：");
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write_ob(ob,"您的人物储存挡出了一些问题，请利用 guest 人物通知巫师处理。\n");
                destruct(ob);
                return;
        } else { // check if someone is already trying to create this id
                if( find_login(ob) ) {
                        write_ob(ob,"有人也在创造这个人物，请选用其他英文名字。\n");
                        write_ob(ob,"您的英文名字：");
                        input_to("get_id", ob);
                        return;
                }
        }

// dts: check reg-ban setting
        if (REGBAN_D->is_banned(query_ip_name(ob)) == 1) {
                write_ob(ob,"本 MUD 不欢迎你创造新的人物。");
                destruct(ob);
                return;
        }

        write_ob(ob,"使用 " + (string)ob->query("id") + " 这个名字将会创造一个新的人物，您确定吗(y/n)？");
        input_to("confirm_id", ob);
}

private void setcheck_password(string pass, object ob)
{
        write_ob(ob,"\n");
        if( strlen(pass)<10 ) {
                write_ob(ob,"保密密码的长度至少要十个字元，请重设您的保密密码：");
                input_to("setcheck_password", 1, ob);
                return;
        }
        ob->set("check_password", crypt(pass,0) );
        write_ob(ob,"请再输入一次您的保密密码，以确认您没记错：");
        input_to("confirm_setcheck_password", 1, ob);
}
private void confirm_setcheck_password(string pass, object ob)
{
        mapping my;
        string old_pass;
        write_ob(ob,"\n");
        old_pass = ob->query("check_password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write_ob(ob,"您两次输入的保密密码并不一样，请重新设定一次保密密码：");
                input_to("setcheck_password", 1, ob);
                return;
       }
        write_ob(ob,"请输入使用密码：");
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
		write_ob(ob,HIR"对不起，你的保密密码不对！\n"NOR);
		destruct(ob);
		return;
	}
        write_ob(ob,"请设定您的新使用密码：");
        input_to("setnew_password", 1, ob);
}

private void setnew_password(string pass, object ob)
{
        write_ob(ob,"\n");
        if( strlen(pass)<5 ) {
                write_ob(ob,"使用密码的长度至少要五个字元，请重设您的使用密码：");
                input_to("setnew_password", 1, ob);
                return;
        }
        ob->set("password", crypt(pass,0) );
        write_ob(ob,"请再输入一次您的使用密码，以确认您没记错：");
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
	                write_ob(ob,"您两次输入的使用密码并不一样，请重新设定一次使用密码：");
	                input_to("setnew_password", 1, ob);
	                return;
		}
		ob->set("pw-gs","no");
                log_file("passwd-gs", sprintf("[%s]  %s(%s)从 [%s] 对密码进行重置。\n", ctime(time()), ob->query("name"), ob->query("id"), query_ip_name(ob)));
        }else{		
	        my_pass = ob->query("password");
		if(pass == "Y" || pass == "y")
		{
			
	                if( wizardp(ob->query("id")) )
	                {
				write_ob(ob,HIR"想知道神仙的保密密码？还是找机会当面问问吧。"NOR);
		                destruct(ob);
		                return;
	               	}
		        if(ob->query("pw-gs") != "yes"){
				write_ob(ob,HIC"请输入你的保密密码进行密码挂失："NOR);
				input_to("gs_passwd", 1, ob);		
				return;
			}
		}
	        if( crypt(pass, my_pass) != my_pass ) {
	                write_ob(ob,"使用密码错误！\n");
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
                        write_ob(ob,"你已经自杀了！怎么能够还魂呢？\n");
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
                write_ob(ob,"您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
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
        write_ob(ob,"请您重新创造这个人物。\n");
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
		write_ob(ob,HIR"对不起，你的保密密码不对！\n"NOR);
		destruct(ob);
		return;
	}
	ob->set("pw-gs","yes");
	ob->set("last_on",time());
        log_file("passwd-gs", sprintf("[%s]  %s(%s)从 [%s] 对密码进行挂失。\n", ctime(time()), ob->query("name"), ob->query("id"), query_ip_name(ob)));
	ob->save();
	write_ob(ob,HIG"您三天后可以重新设定您的使用密码！\n"NOR);
	destruct(ob);
	return;
}

private void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if( yn=="" ) {
                write_ob(ob,"您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write_ob(ob,"好吧，欢迎下次再来。\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "有人从别处( " + query_ip_number(ob)
                        + " )连线取代你所控制的人物。\n");
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
                write_ob(ob,"使用这个名字将会创造一个新的人物，您确定吗(y/n)？");
                input_to("confirm_id", ob);
                return;
        }

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write_ob(ob,"好吧，那么请重新输入您的英文名字：");
                input_to("get_id", ob);
                return;
        }
        write_ob(ob, @TEXT

请输入您的高姓大名，由于这个名字代表你的人物，而且以后不能更改，
务必慎重择名（不雅观的姓名将被删除）。另：请不要选择金庸小说中
已有人物姓名。

TEXT
        );
        write_ob(ob,"您的中文名字：");
        input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
        if( !(arg = check_legal_name(arg,ob) )) {
                write_ob(ob,"您的中文名字：");
                input_to("get_name", ob);
                return;
        }
        //write_ob(ob,"%O\n", ob);
        if( objectp(ob) && ob->query("language") == "BIG5")
                arg = "/adm/daemons/languaged"->toGB(arg);
        ob->set("name", arg);

        write_ob(ob,"请设定您的使用密码：");
        input_to("new_password", 1, ob);
}
private void new_password(string pass, object ob)
{
        write_ob(ob,"\n");
        if( strlen(pass)<5 ) {
                write_ob(ob,"使用密码的长度至少要五个字元，请重设您的使用密码：");
                input_to("new_password", 1, ob);
                return;
        }
        ob->set("password", crypt(pass,0) );
        write_ob(ob,"请再输入一次您的使用密码，以确认您没记错：");
        input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
        mapping my;
        string old_pass;
        write_ob(ob,"\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write_ob(ob,"您两次输入的使用密码并不一样，请重新设定一次使用密码：");
                input_to("new_password", 1, ob);
                return;
        }
				write_ob(ob,HIR"******************************************************************\n"NOR);
				write_ob(ob,HIR"*                                                                *\n"NOR);
				write_ob(ob,HIR"*                       "NOR+NOR"请输入"HIW"保密密码"HIR"                           *\n"NOR);
				write_ob(ob,HIR"*                                                                *\n"NOR);
				write_ob(ob,HIR"*　　"HIW"保密密码"NOR"是你的人物最终归属的"HIY"唯一凭证"NOR"。日常进行游戏时，你所用"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"的是"HIY"使用密码"NOR"。当"HIY"使用密码"NOR"出于某种原因被遗忘，你就可以输入保密密码"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"取回你的人物。这样不用再找神仙重发密码，事实上神仙也"HIY"不会再管"NOR"这事"HIR"*\n"NOR);
				write_ob(ob,HIR"*"NOR"了。因此保密密码的保密非常重要，"HIY"请确保没有第二个人知道，并且还需"HIR"*\n"NOR);
				write_ob(ob,HIR"*"HIY"要你在关键时候能想得起来"NOR"。请设置长度至少十位的保密密码。        "HIR"*\n"NOR);	
				write_ob(ob,HIR"******************************************************************\n"NOR);
        write_ob(ob,"请设定您的保密密码：");
        input_to("check_password", 1, ob);
}

private void check_password(string pass, object ob)
{
        write_ob(ob,"\n");
        if( strlen(pass)<10 ) {
                write_ob(ob,"保密密码的长度至少要十个字元，请重设您的保密密码：");
                input_to("check_password", 1, ob);
                return;
        }
        ob->set("check_password", crypt(pass,0) );
        write_ob(ob,"请再输入一次您的保密密码，以确认您没记错：");
        input_to("confirm_check_password", 1, ob);
}

private void confirm_check_password(string pass, object ob)
{
        mapping my;
        string old_pass;
        write_ob(ob,"\n");
        old_pass = ob->query("check_password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write_ob(ob,"您两次输入的保密密码并不一样，请重新设定一次保密密码：");
                input_to("check_password", 1, ob);
                return;
        }
        write_ob(ob,"
一个人物的先天天赋，决定了游戏中玩家的职业与武功。【神州】现阶段有以下四项重要天赋：

        "HIG"膂力"NOR"："HIC"影响攻击能力及负荷量，某些武功与职业对膂力也有要求。"NOR"
        "HIG"悟性"NOR"："HIC"影响学习武功秘籍、领悟武功的速度及理解师傅的能力。"NOR"      
        "HIG"根骨"NOR"："HIC"影响升级后所增加的体力，以及人物的精力内力最大值。"NOR"
        "HIG"身法"NOR"："HIC"影响防御及躲避的能力，某些职业需要很高的身法。"NOR"
        "HIG"剩余"NOR"："HIC"对游戏没有任何影响，剩余值越低，玩家的其他天赋便越高。"NOR"

您可以自己指定其中一项的值，或者输入 0 交由系统随机产生。
请输入您的选择(0-4)：
");

// april add
	input_to("select_gift", ob);
// april end

/* by april
        my = ([]);
        random_gift(my);
        write_ob(ob,sprintf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]， 剩余[%d]\n",
                                         my["str"], my["int"], my["con"], my["dex"], my["end"]) );

  write_ob(ob,"您接受这一组天赋吗？");
  input_to("get_gift", ob, my);
*/
}

// april add
void select_gift(string yn, object ob)
{
        int i;
        mapping my = ([]);

        if (!sscanf(yn, "%d", i) || i < 0 || i > 4) {
                write("\n输入错误，请重新选择：");
                input_to("select_gift", ob);
                return;
        }
        if (i) {
                write("\n请输入您想要的数值(10-30)：");
                input_to("set_gift", ob, my, i);
        } else get_gift(" ", ob, my, i);
}

void set_gift(string yn, object ob, mapping my, int select)
{
        int i;

        if (!sscanf(yn, "%d", i) || i < 10 || i > 30) {
                write("\n数值错误，请重新输入：");
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
/*                write_ob(ob,sprintf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]， 剩余[%d]\n",
                                         my["str"], my["int"], my["con"], my["dex"], my["end"]) );

                write_ob(ob,"您同意这一组天赋吗？");
                input_to("get_gift", ob, my);
*/

			printf("\n膂力[%s]，悟性[%s]，根骨[%s]，身法[%s]， 剩余[%s]\n",
			display_attr(my["str"]),
			display_attr(my["int"]),
			display_attr(my["con"]),
			display_attr(my["dex"]),
			display_attr(my["end"]));
			
			write("您同意这一组天赋吗？");
			input_to("get_gift", ob, my, select);

        }
        if (yn[0] == 'y' || yn[0] == 'Y') {
                                write_ob(ob,"您的电子邮件地址：");
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
                write_ob(ob,"电子邮件地址需要是 id@address 的格式。\n");
                write_ob(ob,"您的电子邮件地址(我们将用它来通知你最新消息，比如 IP 变更)：");
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
        write_ob(ob,"您要扮演男性(m)的角色或女性(f)的角色？");
        input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
        write_ob(ob,"\n");
        if( gender=="" ) {
                write_ob(ob,"您要扮演男性(m)的角色或女性(f)的角色？");
                input_to("get_gender", ob, user);
                return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "男性");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "女性" );
        else {
                write_ob(ob,"对不起，您只能选择男性(m)或女性(f)的角色：");
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
                write_ob(ob,"现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
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

        user->set("title", "普通百姓");
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
        write_ob(user,"\n目前权限：" + wizhood(user) + "\n");

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

                tell_object(user, HIR "你一年内未服豹胎易筋丸，功力大损！！！\n"NOR);
        }

        user->save();

        if( !silent ) {
                if (ob->query("registered") == 0)
                {
                        //cat(UNREG_MOTD);
write("－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
＊      注意！！！

                  您还没有注册，一部份的命令将只有在注册后才能使用。

                  注册的步骤很简单，您需要给任何大巫师或神寄一封电子
                  邮件（ＥＭＡＩＬ），快则几分钟，慢则一天，就行了。
－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n");
                }
                else
{
                        //cat(MOTD);
                        write(
"－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
＊      请用 help rules 来查询游戏规则。因为犯规被删除的帐号，一律是咎由
        自取，不可能被恢复。对于履次犯规的玩家，【神州】将采取永久关闭登录地
        址的重罚。
＊      新手请用 help，help intro，help newbie， help commands 等命
        令来查询游戏方法，也可以查询【神州】家页上的相关说明。
＊      记住随时存档。由于当机造成的游戏进度损失，【神州】概不负责。
＊      请自杀掉所有不用的帐号。一个月以上不用的废置账号随时可能被清除。
＊      玩家之间的通话内容与言论自由不属于【神州】的保护范围。
－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n");

}
                write(sprintf( HIR"上次连线地址：\t%s( %s )\n\n"NOR,
                        ob->query("last_from"),
                        ctime(ob->query("last_on") )
                ) );

                write(
HIG"
       ********************************************************************
       *                                                                  *
       * 玩家请仔细阅读并遵守 help rules 中的内容，向神仙求救请输入 sos 。*
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
/*	        i=sizeof( NEWS_OB->query("notes") ) - user->query("LastReadNews");
	        if ( i>0 ) write(HIW"您有"NOR+HIG+chinese_number(i)+NOR+HIW"条新闻尚未阅读，请用news命令来阅读，这对你很重要。\n"NOR);
		VOTE->main(user,"list");*/
		write(string_m(BLINK+HIG+"请随时注意公告提示，方法是"HIR"help gonggao"HIG"。\n"NOR,70));

                if( user->is_ghost() )
                        startroom = DEATH_ROOM;
                else if( !stringp(startroom = user->query("startroom"))
                        || !user->query("family") && user->query("combat_exp") < 1)
                        startroom = "/d/city/kedian";

                if (user->query("newbie")== "yes" && wizhood(user) == "(player)")
		{
			CHANNEL_D->do_channel( this_object(), "rumor",sprintf("听说%s(%s)开始闯荡【 神州 】的世界了。", user->name(),user->query("id")));
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
                tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
                        ({user}));
        }
	if( wizhood(user)=="(admin)" || wizhood(user)=="(arch)" || wizhood(user)=="(wizard)") return 0;
        if (!user->query_temp("cursed"))
	if ( !user->query( "blocked" ) )
	     CHANNEL_D->do_channel( this_object(), "sys",
	                 sprintf("%s(%s)由%s连线进入。", user->name(),user->query("id"), query_ip_name(user)) );
        TOPTEN_D->topten_checkplayer(user);
}

varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        user->reconnect();
        if( !silent ) {
                tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
                ({user}));
        }
	if( wizhood(user)=="(admin)" || wizhood(user)=="(arch)" || wizhood(user)=="(wizard)") return 0;
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)由%s重新连线进入。", user->query("name"),user->query("id"), query_ip_name(user)) );
}

int check_legal_id(string id,object ob)
{
        int i;

        i = strlen(id);

        if( (strlen(id) < 3) || (strlen(id) > 8 )
          && (string)SECURITY_D->get_status(id) == "(player)" ) {
                write_ob(ob,"对不起，你的英文名字必须是 3 到 8 个英文字母。\n");
                return 0;
        }
        while(i--)
                if( id[i]<'a' || id[i]>'z' ) {
                        write_ob(ob,"对不起，你的英文名字只能用英文字母。\n");
                        return 0;
                }

        return 1;
}

string check_legal_name(string name,object ob)
{
        int i,j;

        i = strlen(name);

        if( (strlen(name) < 2) || (strlen(name) > 8 ) || i % 2) {
                write_ob(ob,"对不起，你的中文名字必须是 1 到 4 个中文字。\n");
                return 0;
        }
        for (j = 0; j < i; j++) {
//              if( name[i]<=' ' ) {
//                      write_ob(ob,"对不起，你的中文名字不能用控制字元。\n");
//                      return 0;
//              }
                if( j%2==0 && !is_chinese(name[j..j+1]) ) {
                        name[j]+=128; name[j+1]+=128;
//                      write_ob(ob,"对不起，请您用「中文」取名字。\n");
//                      return 0;
                }
        }
        if( member_array(name, banned_name)!=-1 ) {
                write_ob(ob,"对不起，这种名字会造成其他人的困扰。\n");
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
