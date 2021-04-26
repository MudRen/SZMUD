//#pragma optimize all

#include <ansi.h>
#include <localtime.h>

#ifndef BACKUP_DIR
#define BACKUP_DIR "/log/BACKUP/"
#endif

inherit F_DBASE;

void auto_save(int duration);
void remove_old_data();
void backup_data();

void create()
{
	seteuid(getuid());
	set("name", "���̾���");
	set("channel_id", "���̾���(autosave)");
	set("id", "autosave");

	CHANNEL_D->do_channel( this_object(), "sys", "�Զ������Ѿ�������\n");

	remove_call_out("auto_save");
	call_out("auto_save", 10, 0);
}

void auto_save(int duration)
{
	int i;
	object *ob, link_ob;
	mixed *local;
	string id, *alpha =
 ({ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
    "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" });

	seteuid(getuid());

	ob=users();
	i=sizeof(ob);
	while(i--) {
		id = (string) ob[i]->query("id");
		if (!id) continue;

		if( id[0..0] != alpha[2*duration] &&
		    id[0..0] != alpha[2*duration+1] )   continue;

		if(!environment(ob[i]) )        continue;
		if( !objectp(link_ob = ob[i]->query_temp("link_ob")) )  continue;

		link_ob->save();
		ob[i]->save();
                tell_object(ob[i],HIR "��ϵͳ����ʾ�������������Զ������ˡ�\n" NOR);
	}

	duration ++;
	if(duration >= sizeof(alpha)/2 )        duration = 0;

	local = localtime(time());
	if( (local[LT_MDAY] % 10) == 0 && local[LT_HOUR] == 20
	  && local[LT_MIN] == 0 && local[LT_SEC] < 50
	  && time() - query("delete_time") > 86400 ) // Ѯ�׵� 20:00ɾ����ʱ�ı���
		remove_old_data();
	if( (local[LT_MDAY] % 2) && local[LT_HOUR] == 9
	  && local[LT_MIN] == 30 && local[LT_SEC] < 50
	  && time() - query("backup_time") > 86400 ) // ������� 8:00����
		backup_data();

//        remove_call_out("auto_save");
	call_out("auto_save", 30+random(10), duration); //��һ�ε�ʱ����35*13
}

void backup_data()
{
	int i, j, count_l, count_d;
	string *dir, *ppls, *ppls1, *dir1;
	mixed info;

	seteuid(getuid());
	message("system", "\n*** ��ҵ��������У����Ժ�.... ***\n", users());
	dir = get_dir(DATA_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
		ppls1= get_dir(BACKUP_DIR + "login/" + dir[i] + "/");
		dir1 = get_dir(BACKUP_DIR);
		if( !sizeof(dir1) ) {  // ���û�����Ŀ¼������
			mkdir(BACKUP_DIR + "login/");
			mkdir(BACKUP_DIR + "user/");
		}
		if( !sizeof(ppls1) ) {  // ���û�����Ŀ¼������
			mkdir(BACKUP_DIR + "login/" + dir[i] + "/");
			mkdir(BACKUP_DIR + "user/" + dir[i] + "/");
		}
		for(j=0; j<sizeof(ppls); j++) {
			if(ppls[j] == "." || ppls[j] == "..")   continue;
			info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
			if(info[0] == -2)       continue;

			if( (time()-(int)info[1])/86400 <= 2 ) {
				if (cp(DATA_DIR + "login/" + dir[i] + "/" + ppls[j], BACKUP_DIR + "login/" + dir[i] + "/" + ppls[j] ));
					count_l++;
				if (cp(DATA_DIR + "user/" + dir[i] + "/" + ppls[j], BACKUP_DIR + "user/" + dir[i] + "/" + ppls[j]));
					count_d++;
			}
		}
	}
	set("backup_time",time());
	log_file("static/BACKUP", sprintf("Backup user data on %s. %d login's data, %d data's data backuped.\n", ctime(time()), count_l, count_d ));
	message("system", "\n*** ��ҵ���������ϡ�***\n", users());
}

void remove_old_data()
{
	int i, j, count_l, count_d;
	string *dir, *ppls;
	mixed info;

	seteuid(getuid());
	message("system", "\n*** ��ҵ��������У����Ժ�.... ***\n", users());
	dir = get_dir(BACKUP_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		ppls = get_dir(BACKUP_DIR + "login/" + dir[i] + "/");
		for(j=0; j<sizeof(ppls); j++) {
			if(ppls[j] == "." || ppls[j] == "..")   continue;
			info = stat(BACKUP_DIR + "login/" + dir[i] + "/" + ppls[j]);
			if(info[0] == -2)       continue;

			if( (time()-(int)info[1])/86400 > 2 ) {
				rm(BACKUP_DIR + "login/" + dir[i] + "/" + ppls[j] );
					count_l++;
				rm(BACKUP_DIR + "user/" + dir[i] + "/" + ppls[j]);
					count_d++;
			}
		}
	}
	set("delete_time",time());
	log_file("static/BACKUP", sprintf("Delete old user data on %s.  %d login's data, %d data's data deleted.\n", ctime(time()), count_l, count_d ) );
	message("system", "\n*** ��ҵ���������ϡ�***\n", users());
}
