using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;
using System.IO;
using System.Configuration;

namespace BloodDonation.Utils
{
    public static class Cryptograph
    {
        // This constant is used to determine the keysize of the encryption algorithm in bits.
        // We divide this by 8 within the code below to get the equivalent number of bytes.
        private const int Keysize = 256;

        // This constant determines the number of iterations for the password bytes generation function.
        private const int DerivationIterations = 1000;

        public static string Encrypt(string toEncrypt, string useHashing)
        {

            byte[] keyArray;
            byte[] toEncryptArray = UTF8Encoding.UTF8.GetBytes(toEncrypt);

            System.Configuration.AppSettingsReader settingsReader = new AppSettingsReader();
            // Get the key from config file

            string key = (string)settingsReader.GetValue("SecurityKey",
                                                             typeof(String));
            //System.Windows.Forms.MessageBox.Show(key);
            //If hashing use get hashcode regards to your key
            
            MD5CryptoServiceProvider hashmd5 = new MD5CryptoServiceProvider();
            keyArray = hashmd5.ComputeHash(UTF8Encoding.UTF8.GetBytes(key));
            //Always release the resources and flush data
            // of the Cryptographic service provide. Best Practice

            hashmd5.Clear();
            
            TripleDESCryptoServiceProvider tdes = new TripleDESCryptoServiceProvider();
            //set the secret key for the tripleDES algorithm
            tdes.Key = keyArray;
            //mode of operation. there are other 4 modes.
            //We choose ECB(Electronic code Book)
            tdes.Mode = CipherMode.ECB;
            //padding mode(if any extra byte added)

            tdes.Padding = PaddingMode.PKCS7;

            ICryptoTransform cTransform = tdes.CreateEncryptor();
            //transform the specified region of bytes array to resultArray
            byte[] resultArray =
              cTransform.TransformFinalBlock(toEncryptArray, 0,
              toEncryptArray.Length);
            //Release resources held by TripleDes Encryptor
            tdes.Clear();
            //Return the encrypted data into unreadable string format
            return Convert.ToBase64String(resultArray, 0, resultArray.Length);




            //// Salt and IV is randomly generated each time, but is preprended to encrypted cipher text
            //// so that the same Salt and IV values can be used when decrypting.  
            //var saltStringBytes = Generate256BitsOfRandomEntropy();
            //var ivStringBytes = Generate256BitsOfRandomEntropy();
            //var plainTextBytes = Encoding.UTF8.GetBytes(plainText);
            //using (var password = new Rfc2898DeriveBytes(passPhrase, saltStringBytes, DerivationIterations))
            //{
            //    var keyBytes = password.GetBytes(Keysize / 8);
            //    using (var symmetricKey = new RijndaelManaged())
            //    {
            //        symmetricKey.BlockSize = 256;
            //        symmetricKey.Mode = CipherMode.CBC;
            //        symmetricKey.Padding = PaddingMode.PKCS7;
            //        using (var encryptor = symmetricKey.CreateEncryptor(keyBytes, ivStringBytes))
            //        {
            //            using (var memoryStream = new MemoryStream())
            //            {
            //                using (var cryptoStream = new CryptoStream(memoryStream, encryptor, CryptoStreamMode.Write))
            //                {
            //                    cryptoStream.Write(plainTextBytes, 0, plainTextBytes.Length);
            //                    cryptoStream.FlushFinalBlock();
            //                    // Create the final bytes as a concatenation of the random salt bytes, the random iv bytes and the cipher bytes.
            //                    var cipherTextBytes = saltStringBytes;
            //                    cipherTextBytes = cipherTextBytes.Concat(ivStringBytes).ToArray();
            //                    cipherTextBytes = cipherTextBytes.Concat(memoryStream.ToArray()).ToArray();
            //                    memoryStream.Close();
            //                    cryptoStream.Close();
            //                    return Convert.ToBase64String(cipherTextBytes);
            //                }
            //            }
            //        }
            //    }
        }


        public static string Decrypt(string cipherString, string passPhrase)
        {

            byte[] keyArray;
            //get the byte code of the string

            byte[] toEncryptArray = Convert.FromBase64String(cipherString);

            System.Configuration.AppSettingsReader settingsReader =
                                                new AppSettingsReader();
            //Get your key from config file to open the lock!
            string key = (string)settingsReader.GetValue("SecurityKey",
                                                         typeof(String));
            
            //if hashing was used get the hash code with regards to your key
            MD5CryptoServiceProvider hashmd5 = new MD5CryptoServiceProvider();
            keyArray = hashmd5.ComputeHash(UTF8Encoding.UTF8.GetBytes(key));
            //release any resource held by the MD5CryptoServiceProvider

            hashmd5.Clear();
           

            TripleDESCryptoServiceProvider tdes = new TripleDESCryptoServiceProvider();
            //set the secret key for the tripleDES algorithm
            tdes.Key = keyArray;
            //mode of operation. there are other 4 modes. 
            //We choose ECB(Electronic code Book)

            tdes.Mode = CipherMode.ECB;
            //padding mode(if any extra byte added)
            tdes.Padding = PaddingMode.PKCS7;

            ICryptoTransform cTransform = tdes.CreateDecryptor();
            byte[] resultArray = cTransform.TransformFinalBlock(
                                 toEncryptArray, 0, toEncryptArray.Length);
            //Release resources held by TripleDes Encryptor                
            tdes.Clear();
            //return the Clear decrypted TEXT
            return UTF8Encoding.UTF8.GetString(resultArray);


            //// Get the complete stream of bytes that represent:
            //// [32 bytes of Salt] + [32 bytes of IV] + [n bytes of CipherText]
            //var cipherTextBytesWithSaltAndIv = Convert.FromBase64String(cipherText);
            //// Get the saltbytes by extracting the first 32 bytes from the supplied cipherText bytes.
            //var saltStringBytes = cipherTextBytesWithSaltAndIv.Take(Keysize / 8).ToArray();
            //// Get the IV bytes by extracting the next 32 bytes from the supplied cipherText bytes.
            //var ivStringBytes = cipherTextBytesWithSaltAndIv.Skip(Keysize / 8).Take(Keysize / 8).ToArray();
            //// Get the actual cipher text bytes by removing the first 64 bytes from the cipherText string.
            //var cipherTextBytes = cipherTextBytesWithSaltAndIv.Skip((Keysize / 8) * 2).Take(cipherTextBytesWithSaltAndIv.Length - ((Keysize / 8) * 2)).ToArray();

            //using (var password = new Rfc2898DeriveBytes(passPhrase, saltStringBytes, DerivationIterations))
            //{
            //    var keyBytes = password.GetBytes(Keysize / 8);
            //    using (var symmetricKey = new RijndaelManaged())
            //    {
            //        symmetricKey.BlockSize = 256;
            //        symmetricKey.Mode = CipherMode.CBC;
            //        symmetricKey.Padding = PaddingMode.PKCS7;
            //        using (var decryptor = symmetricKey.CreateDecryptor(keyBytes, ivStringBytes))
            //        {
            //            using (var memoryStream = new MemoryStream(cipherTextBytes))
            //            {
            //                using (var cryptoStream = new CryptoStream(memoryStream, decryptor, CryptoStreamMode.Read))
            //                {
            //                    var plainTextBytes = new byte[cipherTextBytes.Length];
            //                    var decryptedByteCount = cryptoStream.Read(plainTextBytes, 0, plainTextBytes.Length);
            //                    memoryStream.Close();
            //                    cryptoStream.Close();
            //                    return Encoding.UTF8.GetString(plainTextBytes, 0, decryptedByteCount);
            //                }
            //            }
            //        }
            //    }
            //}
        }

        private static byte[] Generate256BitsOfRandomEntropy()
        {
            var randomBytes = new byte[32]; // 32 Bytes will give us 256 bits.
            using (var rngCsp = new RNGCryptoServiceProvider())
            {
                // Fill the array with cryptographically secure random bytes.
                rngCsp.GetBytes(randomBytes);
            }
            return randomBytes;
        }
    }
}

