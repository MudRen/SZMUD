// Code of ShenZhou
// regi.c	����ү (registrator)
//change email register to online register for Mudos under win32 by lbc
#ifndef QUEUEDIR
#define QUEUEDIR "/queue/"
#endif
#define REGDATA QUEUEDIR + "register"
#define LOCKDATA QUEUEDIR + "register.lock"

inherit F_DBASE;

string *banned_string = ({
//	"usa.net",
//	"geocities",
//	"bbs",
//	"hotmail",
//	"nc.jx.cn",
	"hotmail"
});

int is_banned_email(string str)
{
	int i;
	string cstr = lower_case(str);

	// if email containing "."
	if (strsrch(cstr, ".") == -1)
		return 1;
	// if email containing "@"
	if (strsrch(cstr, "@") == -1)
		return 1;

	// if email contains invalid strings
       for (i = 0; i < sizeof(banned_string); i++)
                if (strsrch(cstr, banned_string[i]) != -1)
                        return 2;

	if (REGBAN_D->is_banned(cstr) == 1)
		return 2;

        return 0;
}

int register_char(string who, string where);
int change_password(string who, string what);

void create()
{
	seteuid(getuid());
	set("channel_id", "ע�ᾫ��");
}

void save_data(string who, string where, string what)
{
	write_file(REGDATA, who + ":" + where + ":" + what + "\n");
}
string random_password()
{
	return sprintf("%c%c%c%c%c", 97 + random(26), 
		97 + random(26), 97 + random(26),
		97 + random(26), 97 + random(26));
}

int register_char(string who, string where)
{
	object ob, body;
	string pass;

	ob = new(LOGIN_OB);
	ob->set("id", who);
	if (!ob->restore())
		return notify_fail("��Ҫ��˭�Ǽǣ�\n");
	if (SECURITY_D->get_status(who) != "(player)")
		return notify_fail("�Ǽ�ʧ�ܡ�\n");
//	if (!wizardp(this_player()) && ob->query("registered") == "yes")
//		return notify_fail(who + "�Ѿ��Ǽǹ��ˡ�\n");
        if (file_size(LOCKDATA) != -1)
                return notify_fail("���һ��������Ǽǣ�\n");
	pass = ob->query("passwd");
	ob->set("email", where);
	ob->set("password", crypt(pass, 0));
	ob->set("registered", "yes");
	save_data(ob->query("id"), where, pass);
	CHANNEL_D->do_channel(this_object(), "sys", sprintf("%s(%s)���ע�ᣬ�����ʼ���ַ��%s", ob->query("name"), who, where));
	if (objectp(body = find_player(who)) && geteuid(body) == who) {
		log_file("REGISTER", sprintf("[%s] %s registered as %s from %s.\n", 
			ctime(time()), body->query("id"), where, query_ip_name(body)));
		tell_object(body, "������������"+pass+"\n�����µ��������ߣ���\n");
		body->set("registered", "yes");
		body->delete("passwd",1);
		body->set("newbie",1);
		body->save();
		destruct(body);
	}
	ob->save();
	destruct(ob);
	return 1;
}

int change_password(string who, string what)
{
	object ob;
        ob = find_player(who);
	if (ob && geteuid(ob) == who) ob = ob->query_temp("link_ob");
	else ob = 0;
	if (!ob) ob = new(LOGIN_OB);
        ob->set("id", who);
        if (!ob->restore())
               	return notify_fail("��Ҫ��˭�����룿\n");
        ob->set("password", crypt(what, 0));
    	ob->save();
        write("����Ļ��ɹ���\n");
	return 1;
}

int change_name(string who, string what)
{
	object ob;
        ob = find_player(who);
	if (ob && geteuid(ob) == who) ob = ob->query_temp("link_ob");
	else ob = 0;
	if (!ob) ob = new(LOGIN_OB);
        ob->set("id", who);
        if (!ob->restore())
               	return notify_fail("��Ҫ��˭��ԭ��������\n");
        ob->set("name", what);
    	ob->save();
        write("�����Ļ��ɹ���\n");
	return 1;
}

int change_id(string who, string what)
{
	object ob1, ob2, ob3;
	ob1 = new(LOGIN_OB);
        ob1->set("id", who);
	ob2 = new(USER_OB);
	ob2->set("id", who);
        if (!ob1->restore() || !ob2->restore()) {
		destruct(ob1);
		destruct(ob2);
               	return notify_fail("��Ҫ��˭��Ӣ�����֣�\n");
	}
	ob3 = new(LOGIN_OB);
	ob3->set("id", what);
	if (ob3->restore()) {
		destruct(ob1);
		destruct(ob2);
		destruct(ob3);
		return notify_fail("������ʹ�ô�Ӣ������");
	}
	if (SECURITY_D->get_status(who) != "(player)"
	 || SECURITY_D->get_status(what) != "(player)" ) {
		destruct(ob1);
		destruct(ob2);
		destruct(ob3);
		return notify_fail("ָ��ʧ�ܡ�\n");
	}
	ob1->set("id", what);
	ob2->set("id", what);
	ob1->save();
	ob2->save();
        rm(DATA_DIR + "login/" + who[0..0] + "/" + who + SAVE_EXTENSION);
        rm(DATA_DIR + "user/" + who[0..0] + "/" + who + SAVE_EXTENSION);
	destruct(ob1);
	destruct(ob2);
	destruct(ob3);

        write("�Ļ��ɹ���\n");
	return 1;
}
