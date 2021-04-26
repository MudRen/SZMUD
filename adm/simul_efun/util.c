// util.c
#include <localtime.h>
#include <ansi.h>
string process_bar(int n)
{
        string sp;
        int start;

        if (n < 0) n = 0; else
        if (n > 100) n = 100;

        sp = "                                                  " NOR;
        if (n == 100)
        {
                sp[22] = '1';
                sp[23] = '0';
                sp[24] = '0';
                sp[25] = '%';
                start = 22;
        } else
        if (n >= 10)
        {
                sp[23] = (n / 10) + '0';
                sp[24] = (n % 10) + '0';
                sp[25] = '%';
                start = 23;
        } else
        {
                sp[24] = n + '0';
                sp[25] = '%';
                start = 24;
        }

        n /= 2;
        if (start > n)
        {
                sp = sp[0..start-1] + HIY + sp[start..<0];
                sp = sp[0..n - 1] + BBLU + sp[n..<0];
        } else
        {
                sp = sp[0..n - 1] + BBLU + sp[n..<0];
                sp = sp[0..start-1] + HIY + sp[start..<0];
        }

        sp = NOR + BCYN + sp;
        return sp;
}

// sort a chinese string (must be chinese), align the
// string with then len. the prefix is used when the desc
// will be lead by another string or space with length is prefix.
string sort_string(string input, int width, int prefix)
{
#ifdef DOING_IMPROVED
        return efun::sort_string(input, width, prefix);
#else
        int i;
        int sl;
        int len;
        int esc;
        string result;

        result = "";

        len = prefix;
        esc = 0;
        sl = strlen(input);
        for (i = 0; i < sl; i++)
        {
                if (len >= width && input[i] != '\n')
                {
                        int k;
                        k = i;
                        if (input[i] == 27)
                                while (k < sl && input[k++] != 'm');

                        switch ((k < sl - 1) ? input[k..k+1] : 0)
                        {
                        case "��":
                        case "��":
                        case "��":
                        case "��":
                        case "��":
                        case "��":
                        case " )":
                        case "��":
                        case "��":
                        case "��":
                                if (k != i)
                                {
                                        result += input[i..k + 1];
                                        i = k + 1;
                                        continue;
                                }
                                break;
                        default:
                                len = 0;
                                result += "\n";
                                break;
                        }
                }

                if (input[i] == 27)
                        esc = 1;

                if (! esc)
                {
                        if (input[i] > 160)
                        {
                                result += input[i..i+1];
                                i ++;
                                len += 2;
                                continue;
                        }
                        if (input[i] == '\n')
                        {
                                result += "\n";
                                len = 0;
                                continue;
                        }
                }

                result += input[i..i];
                if (! esc) len++;

                if (esc && input[i] == 'm')
                        esc = 0;
        }

        if (i < sl)
                result += input[i..sl-1];

	if (len) result += "\n";

        return result;
#endif
}

#ifndef DOING_IMPROVED
int binary_valid(string file)
{
        return 1;
}
#endif

object get_object(string name)
{
        object ob;
        if (ob = find_object(name))
                return ob;
        return load_object(name);
}

// calculate the color char in a string
int color_len(string str)
{
        int i;
        int extra;

        extra = 0;
        for (i = 0; i < strlen(str); i++)
        {
                if (str[i] == ESC[0])
                {
                        while ((extra++, str[i] < 'A' ||
                                         str[i] > 'z' ||
                                         str[i] > 'Z' && str[i] < 'a') && i < strlen(str))
                                i++;
                }
        }
        return extra;
}

// to a appromix time
string appromix_time(int n, int flag)
{
        string s;
        string os;
        int odd;
        int bn;

        if (n <= 0)
                return flag ? "���Ͼ�" : "����";

        bn = 1;
        if (n < bn * 60)
        {
                // bn ��λ������
                s = "����";
                odd = 0;
        } else
        if (bn *= 60, n < bn * 60)
        {
                // bn ��λ�Ƿ���
                s = "����";
                os = "����";
                odd = n % bn;
                n /= bn;
        } else
        if (bn *= 60, n < 24 * bn)
        {
                // bn ��λ��Сʱ
                s = "Сʱ";
                os = "����";
                odd = (n % bn) / 60;
                n /= bn;
        } else
        if (bn *= 24, n < 30 * bn)
        {
                // bn ��λ����
                s = "��";
                os = "Сʱ";
                odd = (n % bn) / (60 * 60);
                n /= bn;
        } else
        if (n < 365 * bn)
        {
                // bn ��λ����
                s = "����";
                os = "��";
                odd = (n % (30 * bn)) / bn;
                n /= 30 * bn;
        } else
        {
                // bn ��λ����
                s = "��";
                os = "����";
                odd = (n % (365 * bn)) / (bn * 30);
                n /= 365 * bn;
        }

        s = chinese_number(n) + s;
        if (odd)
                s += "��" + chinese_number(odd) + os;

        if (flag) s += "�Ժ�";
        return s;
}

// filter color
string filter_color(string arg)
{
#ifdef DOING_IMPROVED
        return efun::filter_ansi(arg);
#else
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
        arg = replace_string(arg, BOLD, "");
        arg = replace_string(arg, BLINK, "");
        return arg;
#endif
}

string up_case(string arg)
{
        int i;
        for (i = 0; i < strlen(arg); i++)
                if (arg[i] >= 'a' && arg[i] <= 'z')
                        arg[i] = arg[i] - 32;
        return arg;
}

// append color after the $N��$n��$w for the string color won't be
// break by the NOR after the name
string append_color(string arg, string default_color)
{
        arg = replace_string(arg, "$N", "$N" + default_color);
        arg = replace_string(arg, "$n", "$n" + default_color);
        arg = replace_string(arg, "$w", "$w" + default_color);
        return arg;
}

// change to english sigh to chinese
string chinese_desc(string arg)
{
        arg = replace_string(arg, ",", "��");
        arg = replace_string(arg, "!", "��");
        return arg;
}

// is the string1 be a substring of string2
int is_sub(string s_str, string m_str)
{
        if (! m_str || ! s_str) return 0;
        return strsrch("," + m_str + ",", "," + s_str + ",") != -1;
}

// add a s_str
string add_sub(string s_str, string m_str)
{
        string *slist;
        int i;

        if (! s_str || is_sub(s_str, m_str))
                return m_str;

        slist = explode(s_str, ",");
        slist -= ({ "" });
        for (i = 0; i < sizeof(slist); i++)
                if (! is_sub(slist[i], m_str))
                        if (m_str == 0 || m_str == "")
                                m_str = slist[i];
                        else
                                m_str += "," + slist[i];

        return m_str;
}

// remove a s_str
string remove_sub(string s_str, string m_str)
{
        string *slist;
        string *trilist;

        if (! m_str || m_str == s_str) return 0;
        slist = explode(m_str, ",") - ({ "" });
        trilist = explode(s_str, ",");
        slist -= trilist;
        if (! sizeof(slist)) return 0;
        m_str = implode(slist, ",");
        return m_str;
}

// check the id is legal
int is_legal_id(string id)
{
        int i;

        if (! id) return 0;

        for (i = 0; i < strlen(id); i++)
		if (id[i] < 'a' || id[i] > 'z')
                        return 0;

        return 1;
}

// generate the short id for log
string log_id(object ob, int raw)
{
        string msg;
        if (raw) return sprintf("%-8s", geteuid(ob));

        msg = sprintf("%s(%s)", ob->name(1), geteuid(ob));
        msg = sprintf("%-16s", msg);
        return msg;
}

// generate time
string log_time()
{
        string msg = ctime(time());

        msg = msg[4..6] + "/" + msg[8..9] + "/" +
              msg[20..23] + " " + msg[11..18];
        return msg;
}

// can the two man talk with together ?
int can_talk_with(object ob1, object ob2)
{
        if (! objectp(ob1) || ! objectp(ob2))
                return 0;

        if (! living(ob1) || ! living(ob2))
                return 0;

        if (environment(ob1) != environment(ob2))
                return 0;

        if (ob1->is_fighting() || ob2->is_fighting())
                return 0;

        return 1;
}

// build file crypt key
string file_crypt(string file)
{
#ifdef DOING_IMPROVED
        return efun::file_crypt(file);
#else
        return "1234567890ABCDEF";
#endif
}

// check the file valid
int file_valid(string file)
{
#ifdef DOING_IMPROVED
        return efun::file_valid(file);
#else
        return file_size(file) > 0;
#endif
}
string setcolor(string msg, int raw)
{
        msg = replace_string(msg, "$BLK$", NOR+BLK);
        msg = replace_string(msg, "$RED$", NOR+RED);
        msg = replace_string(msg, "$GRN$", NOR+GRN);
        msg = replace_string(msg, "$YEL$", NOR+YEL);
        msg = replace_string(msg, "$BLU$", NOR+BLU);
        msg = replace_string(msg, "$MGA$", NOR+MAG);
        msg = replace_string(msg, "$CYN$", NOR+CYN);
        msg = replace_string(msg, "$WHT$", NOR+WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        if (raw == 1){
	        msg = replace_string(msg, "$HBRED$", HBRED);
	        msg = replace_string(msg, "$HBGRN$", HBGRN);
	        msg = replace_string(msg, "$HBYEL$", HBYEL);
	        msg = replace_string(msg, "$HBBLU$", HBBLU);
	        msg = replace_string(msg, "$HBMAG$", HBMAG);
	        msg = replace_string(msg, "$HBCYN$", HBCYN);
	        msg = replace_string(msg, "$HBWHT$", HBWHT);
	        msg = replace_string(msg, "$BBLK$", BBLK);
	        msg = replace_string(msg, "$BRED$", BRED);
	        msg = replace_string(msg, "$BGRN$", BGRN);
	        msg = replace_string(msg, "$BYEL$", BYEL);
	        msg = replace_string(msg, "$BBLU$", BBLU);
	        msg = replace_string(msg, "$BMAG$", BMAG);
	        msg = replace_string(msg, "$BCYN$", BCYN);
	        msg = replace_string(msg, "$SPARK$", BLINK);
        }else if (raw == 2){
		msg = replace_string(msg, "$BOLD$", BOLD);
	        msg = replace_string(msg, "$CLR$", CLR);
	        msg = replace_string(msg, "$HOME$", HOME);
	        msg = replace_string(msg, "$REF$", REF);
	        msg = replace_string(msg, "$BIGTOP$", BIGTOP);
	        msg = replace_string(msg, "$BIGBOT$", BIGBOT);
	        msg = replace_string(msg, "$SAVEC$", SAVEC);
	        msg = replace_string(msg, "$REST$", REST);
	        msg = replace_string(msg, "$SINGW$", SINGW);
	        msg = replace_string(msg, "$DBL$", DBL);
	        msg = replace_string(msg, "$FRTOP$", FRTOP);
	        msg = replace_string(msg, "$FRBOT$", FRBOT);
	        msg = replace_string(msg, "$UNFR$", UNFR);
	        msg = replace_string(msg, "$U$", U);
	        msg = replace_string(msg, "$REV$", REV);
	        msg = replace_string(msg, "$HIREV$", HIREV);
	}
	return msg+NOR;
}

string delcolor(string msg)
{
        msg = replace_string(msg, BLK, "");
        msg = replace_string(msg, RED, "");
        msg = replace_string(msg, GRN, "");
        msg = replace_string(msg, YEL, "");
        msg = replace_string(msg, BLU, "");
        msg = replace_string(msg, MAG, "");
        msg = replace_string(msg, CYN, "");
        msg = replace_string(msg, WHT, "");
        msg = replace_string(msg, HIR, "");
        msg = replace_string(msg, HIG, "");
        msg = replace_string(msg, HIY, "");
        msg = replace_string(msg, HIB, "");
        msg = replace_string(msg, HIM, "");
        msg = replace_string(msg, HIC, "");
        msg = replace_string(msg, HIW, "");
        msg = replace_string(msg, NOR, "");
        msg = replace_string(msg, HBRED, "");
        msg = replace_string(msg, HBGRN, "");
        msg = replace_string(msg, HBYEL, "");
        msg = replace_string(msg, HBBLU, "");
        msg = replace_string(msg, HBMAG, "");
        msg = replace_string(msg, HBCYN, "");
        msg = replace_string(msg, HBWHT, "");
        msg = replace_string(msg, BBLK, "");
        msg = replace_string(msg, BRED, "");
        msg = replace_string(msg, BGRN, "");
        msg = replace_string(msg, BYEL, "");
        msg = replace_string(msg, BBLU, "");
        msg = replace_string(msg, BMAG, "");
        msg = replace_string(msg, BCYN, "");
        msg = replace_string(msg, BLINK, "");
/*	msg = replace_string(msg, BOLD, "");
        msg = replace_string(msg, CLR, "");
        msg = replace_string(msg, HOME, "");
        msg = replace_string(msg, REF, "");
        msg = replace_string(msg, BIGTOP, "");
        msg = replace_string(msg, BIGBOT, "");
        msg = replace_string(msg, SAVEC, "");
        msg = replace_string(msg, REST, "");
        msg = replace_string(msg, SINGW, "");
        msg = replace_string(msg, DBL, "");
        msg = replace_string(msg, FRTOP, "");
        msg = replace_string(msg, FRBOT, "");
        msg = replace_string(msg, UNFR, "");
        msg = replace_string(msg, U, "");
        msg = replace_string(msg, REV, "");
        msg = replace_string(msg, HIREV, "");*///discard by Karlopex@sz
	return msg;
}
int string_l(string msg, int mode)
{
	if ( mode == 1 )
		return strlen(delcolor(msg));
	else return strlen(msg);
}
string string_m(string name, int long)
{
	int cnt, s, x = string_l(name,1);
	string blk, newstring = "", blank = "                                                                                                        ";
	s = ( (long - x)/2 )-1;
	cnt = sizeof(explode( name, "\n" ));
	blk = blank[0..s];
	if (cnt <= 1){
		if (x >= long) return name;
		else if (x < long) return blk + name + blk;
	}else{
		for(int i=0;i<cnt;i++){
			newstring += (i==0 || i==cnt)?"":"\n";
			newstring += replace_string(string_m(explode( name, "\n" )[i],long), "\n", "");
		}
		return newstring;
	}
}
